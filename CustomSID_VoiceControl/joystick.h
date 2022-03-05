#ifndef __JOYSTICK_H_
#define __JOYSTICK_H_

extern float JOYSTICK_FWD_FACTOR; //reduce to slow down
extern float JOYSTICK_TURN_FACTOR; //reduce to slow down

void setVoltage(uint8_t ch, float v);
void setJoystick(float speed, float dir);
void joystickCenter();
void joystickForward();
void joystickLeft();
void joystickRight();
void joystickReverse();
void joystickVeerLeft();
void joystickVeerRight();
void setupJoystick();

#endif