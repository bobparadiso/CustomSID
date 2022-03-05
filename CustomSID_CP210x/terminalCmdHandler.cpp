#include <Arduino.h>
#include <stdlib.h>

#include "Trace.h"
#include "joystick.h"

#define SID_BUILD_VERSION "1.0"

extern uint32_t OPTION_DURATION;
extern uint32_t CONTINUE_DURATION;

extern uint32_t lastRx;

void safeDelay(uint32_t duration);

//
void terminalCmdHandler(char *cmd)
{
	tracef("got CMD: %s\r\n", cmd);
	if (strcmp(cmd, "help") == 0)
	{
		tracef("SID version:%s\r\n", SID_BUILD_VERSION);
		trace("command list:\r\n");
		trace("help\r\n");
	}
	else if (strcmp(cmd, "EyeGaze") == 0)
	{
		trace("JoystickX0.1\r\n");
	}
	else if (strcmp(cmd, "v") == 0)
	{
		uint8_t ch = atoi(strtok(NULL, " \r\n"));
		float v = atof(strtok(NULL, " \r\n"));
		tracef("v: ch:%d v:%.2f\r\n", ch, v);
		setVoltage(ch, v);
	}
	else if (strcmp(cmd, "press") == 0)
	{
		float speed = atof(strtok(NULL, " \r\n"));
		float dir = atof(strtok(NULL, " \r\n"));
		int16_t time = atoi(strtok(NULL, " \r\n"));
		tracef("press: speed:%.2f dir:%.2f time:%d\r\n", speed, dir, time);
		setJoystick(speed, dir);
		if (time != -1)
		{
			safeDelay(time);
			joystickCenter();
		}
	}
	else if (strcmp(cmd, "forward") == 0)
	{
		joystickForward();
		lastRx = millis();
	}
	else if (strcmp(cmd, "reverse") == 0)
	{
		joystickReverse();
		lastRx = millis();
	}
	else if (strcmp(cmd, "left") == 0)
	{
		joystickLeft();
		lastRx = millis();
	}
	else if (strcmp(cmd, "right") == 0)
	{
		joystickRight();
		lastRx = millis();
	}
	else if (strcmp(cmd, "mode") == 0)
	{
		joystickCenter();
		pinMode(MODE_PIN, OUTPUT);
		lastRx = millis();
	}
	else if (strcmp(cmd, "stop") == 0)
	{
		joystickCenter();
		pinMode(MODE_PIN, INPUT);
		lastRx = millis();
	}
	else if (strcmp(cmd, "continue_duration") == 0)
	{
		CONTINUE_DURATION = atoi(strtok(NULL, " \r\n"));
		tracef("CONTINUE_DURATION: %d\r\n", CONTINUE_DURATION);
	}
	else if (strcmp(cmd, "joystick_fwd_factor") == 0)
	{
		JOYSTICK_FWD_FACTOR = atof(strtok(NULL, " \r\n"));
		tracef("JOYSTICK_FWD_FACTOR: %.2f\r\n", JOYSTICK_FWD_FACTOR);
	}
	else if (strcmp(cmd, "joystick_turn_factor") == 0)
	{
		JOYSTICK_TURN_FACTOR = atof(strtok(NULL, " \r\n"));
		tracef("JOYSTICK_TURN_FACTOR: %.2f\r\n", JOYSTICK_TURN_FACTOR);
	}
	else if (strcmp(cmd, "watchdog") == 0)
	{
		trace("testing watchdog; spinning...\r\n");
		while(1);
	}
	else if (cmd)
	{
		joystickCenter();
		pinMode(MODE_PIN, INPUT);
		trace("ERROR\r\n");
	}
}
