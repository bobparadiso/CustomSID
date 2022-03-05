#include <Arduino.h>
#include "DebouncedButton.h"

//
DebouncedButton::DebouncedButton(uint8_t _switchPin)
{
	switchPin = _switchPin;
	debounceCount = 0;
	lastState = 0;
	debouncedState = 0;
	
	pinMode(switchPin, INPUT_PULLUP);
}

//
void DebouncedButton::update()
{
	uint8_t state = digitalRead(switchPin) == LOW;
	//increment count if state is maintained
	if (state == lastState)
	{
		debounceCount++;
		if (debounceCount == DEBOUNCE_ITERATIONS)
			debouncedState = lastState;
	}
	//store last button state and reset count
	else
	{
		debounceCount = 0;
		lastState = state;
	}
}
