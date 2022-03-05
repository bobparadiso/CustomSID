#ifndef __DEBOUNCED_BUTTON_H_
#define __DEBOUNCED_BUTTON_H_

#include <stdint.h>

#define BTN_POLL_INTERVAL 10 //ms
#define DEBOUNCE_TIME 50 //ms
#define DEBOUNCE_ITERATIONS (DEBOUNCE_TIME / BTN_POLL_INTERVAL)

class DebouncedButton
{
public:
	DebouncedButton(uint8_t _switchPin);
	void update();
	uint8_t getVal() {return debouncedState;}

private:
	uint8_t switchPin;
	volatile uint16_t debounceCount;
	volatile uint8_t lastState;
	volatile uint8_t debouncedState;
};

#endif