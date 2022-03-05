//running on Adafruit Feather M0

#include <SPI.h>
#include <Adafruit_SleepyDog.h>
#include "avdweb_SAMDtimer.h"

#include "DebouncedButton.h"
#include "Terminal.h"
#include "Trace.h"

#include "joystick.h"
#include "display.h"

#define DISPLAY_SPEED_PIN A0
#define DISPLAY_BRIGHTNESS_PIN A1
#define SWITCH_PIN A2

void updateBtnState(struct tc_module *const module_inst);

DebouncedButton btn(SWITCH_PIN);
SAMDtimer btnTimer = SAMDtimer(4, updateBtnState, BTN_POLL_INTERVAL * 1000, 0);

uint8_t DISPLAY_BRIGHTNESS_MIN = 10;
uint8_t DISPLAY_BRIGHTNESS_MAX = 255;
uint8_t DISPLAY_BRIGHTNESS = DISPLAY_BRIGHTNESS_MAX;
#define BRIGHTNESS_CHANGE_THRESHOLD 3

uint32_t OPTION_DURATION_MIN = 250;
uint32_t OPTION_DURATION_MAX = 1500;
uint32_t OPTION_DURATION = OPTION_DURATION_MAX;

uint32_t CONTINUE_DURATION = 500;

//
void safeDelay(uint32_t duration)
{
	uint32_t start = millis();
	while (millis() - start < duration)
		Watchdog.reset();
}

//
void updateBtnState(struct tc_module *const module_inst)
{
	btn.update();
}

//
void setup()
{
	Watchdog.enable(4000);

	Serial.begin(115200);

	SPI.begin();
	setupJoystick();
	
	setupDisplay();
	
	btnTimer.enableInterrupt(1);
	
	trace("ready.");
	
	enum OPTIONS {O_FWD, O_LT, O_RT, O_REV, O_VLT, O_VRT, O_NONE, O_CNT};
	uint8_t option = O_FWD;
	uint8_t activeOption = O_NONE;
	sendDisplayDirection(option, 0);
	uint32_t optionDisplayStart = millis();
	uint32_t continueStart;
	
	uint8_t prevDisplayBrightness = 0;
	
	while(1)
	{
		Watchdog.reset();
		processSerial();
		
		OPTION_DURATION = map(analogRead(DISPLAY_SPEED_PIN), 0, 1023, OPTION_DURATION_MIN, OPTION_DURATION_MAX);
		DISPLAY_BRIGHTNESS = map(analogRead(DISPLAY_BRIGHTNESS_PIN), 0, 1023, DISPLAY_BRIGHTNESS_MIN, DISPLAY_BRIGHTNESS_MAX);
		
		if (abs(prevDisplayBrightness - DISPLAY_BRIGHTNESS) > BRIGHTNESS_CHANGE_THRESHOLD)
		{
			sendDisplayBrightness(DISPLAY_BRIGHTNESS);
			prevDisplayBrightness = DISPLAY_BRIGHTNESS;
		}
		
		//update option
		if (activeOption == O_NONE)
		{
			if (millis() - optionDisplayStart > OPTION_DURATION)
			{
				option = (option + 1) % 4;
				//tracef("option: %d\r\n", option);
				sendDisplayDirection(option, 0);
				optionDisplayStart = millis();
			}
		}
		else if (activeOption == O_FWD)
		{
			if (millis() - optionDisplayStart > OPTION_DURATION)
			{
				if (option == O_VLT)
					option = O_VRT;
				else
					option = O_VLT;
				
				//tracef("option: %d\r\n", option);
				sendDisplayDirection(option, 0);
				optionDisplayStart = millis();
			}
		}
		
		//switch currently activated
		if (btn.getVal())
		{
			if (activeOption == O_NONE || activeOption == O_CNT)
			{
				switch (option)
				{
				case O_FWD: joystickForward(); break;
				case O_LT: joystickLeft(); break;
				case O_RT: joystickRight(); break;
				case O_REV: joystickReverse(); break;

				case O_VLT: joystickVeerLeft(); break;
				case O_VRT: joystickVeerRight(); break;
				}
				activeOption = option;

				//start showing veering options
				if (option == O_FWD)
				{
					option = O_VLT;
					sendDisplayDirection(option, 0);
					optionDisplayStart = millis();
				}
				else
				{
					sendDisplayDirection(activeOption, 1);
				}
			}
		}
		//switch currently released
		else
		{
			//end continuation
			if (activeOption == O_CNT)
			{
				if (millis() - continueStart > CONTINUE_DURATION)
				{
					joystickCenter();
					activeOption = O_NONE;
					option = O_FWD;
					sendDisplayDirection(option, 0);
					optionDisplayStart = millis();
				}
			}
			//start continuation
			else if (activeOption == O_FWD)
			{
				continueStart = millis();
				activeOption = O_CNT;
			}
			else if (activeOption == O_VLT || activeOption == O_VRT)
			{
				continueStart = millis();
				activeOption = O_CNT;

				//change to FWD and set that as option
				joystickForward();
				option = O_FWD;
				sendDisplayDirection(option, 1);
				optionDisplayStart = millis();
			}
			//stop movement
			else if (activeOption != O_NONE)
			{
				joystickCenter();
				activeOption = O_NONE;
				option = O_FWD;
				sendDisplayDirection(option, 0);
				optionDisplayStart = millis();
			}
		}
	}
	
	joystickCenter();
}

//
void loop() {}
