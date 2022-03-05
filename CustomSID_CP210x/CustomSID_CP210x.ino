//running on Adafruit Feather M0

#include <SPI.h>
#include <Adafruit_SleepyDog.h>
#include "avdweb_SAMDtimer.h"

#include "DebouncedButton.h"
#include "Terminal.h"
#include "Trace.h"

#include "joystick.h"
#include "display.h"
#include "glosdex.h"

#define DISPLAY_SPEED_PIN A0
#define DISPLAY_BRIGHTNESS_PIN A1
#define SWITCH_PIN A2

#define RX_TIMEOUT 250

#define SERIAL_PORT Serial1

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

uint32_t lastRx = 0;

//
void setup()
{
	Watchdog.enable(4000);

	Serial.begin(115200);
	Serial1.begin(115200);

	SPI.begin();
	setupJoystick();
	
	setupGlosdex();
	
	//bptxxx: spin in spot
	//safeDelay(10000);
	//setJoystick(0.0f, 1.0f);
	
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
		
		updateGlosdex();
		processSerial();
		
		//cut everything
		//if (millis() - lastRx > RX_TIMEOUT)
		//TODO: reinstate
		if (0) //bptxxx
		{
			joystickCenter();
			pinMode(MODE_PIN, INPUT);
			trace("rx timeout");
		}

		//if (!btn.getVal())
		//	joystickCenter();
	}
}

//
void loop() {}
