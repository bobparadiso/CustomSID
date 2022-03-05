#include <Arduino.h>
#include <stdlib.h>
#include <SPI.h>
#include "Terminal.h"
#include "Trace.h"
#include "joystick.h"

#define SS_PIN 9
#define nRES_PIN 10

#define SPD_CH 0
#define DIR_CH 1
#define REF_CH 2

#define REF_VOLTAGE 6.0
#define VOLTAGE_SWING 1.1

#define SETUP_TIME 1


void safeDelay(uint32_t duration);

//
void setPot(uint8_t ch, uint8_t val)
{
	//release "reset" if we haven't yet
	digitalWrite(nRES_PIN, HIGH);

	// take the SS pin low to select the chip:
	digitalWrite(SS_PIN, LOW);
	safeDelay(SETUP_TIME);
	//  send in the address and value via SPI:
	SPI.transfer(ch);
	SPI.transfer(val);
	safeDelay(SETUP_TIME);
	// take the SS pin high to de-select the chip:
	digitalWrite(SS_PIN, HIGH);
}

//
void setVoltage(uint8_t ch, float v)
{
	uint8_t val = (uint8_t)constrain(v/12.0*255.0 + 0.5, 0.0, 255.0);
	tracef("v ch:%d v:%.2f val:%d\r\n", ch, v, val);
	setPot(ch, val);
}

//
float JOYSTICK_FWD_FACTOR = 1.0;
float JOYSTICK_TURN_FACTOR = 1.0;
void setJoystick(float speed, float dir)
{
	tracef("setJoystick: spd:%.2f dir:%.2f\r\n", speed, dir);
	speed = constrain(speed*JOYSTICK_FWD_FACTOR, -1.0f, 1.0f);
	dir = constrain(dir*JOYSTICK_TURN_FACTOR, -1.0f, 1.0f);
	
	setVoltage(SPD_CH, REF_VOLTAGE + speed * VOLTAGE_SWING);
	setVoltage(DIR_CH, REF_VOLTAGE + dir * VOLTAGE_SWING);
}

//
void joystickCenter() { setJoystick(0.0f, 0.0f); }
void joystickForward() { setJoystick(1.0f, 0.0f); }
void joystickLeft() { setJoystick(0.0f, -1.0f); }
void joystickRight() { setJoystick(0.0f, 1.0f); }
void joystickReverse() { setJoystick(-1.0f, 0.0f); }
void joystickVeerLeft() { setJoystick(1.0f, -1.0f); }
void joystickVeerRight() { setJoystick(1.0f, 1.0f); }

//
void setupJoystick()
{
	pinMode(SS_PIN, OUTPUT);
	digitalWrite(SS_PIN, HIGH);
	SPI.begin();

	pinMode(nRES_PIN, OUTPUT);

	setVoltage(REF_CH, REF_VOLTAGE);
	joystickCenter();
}
