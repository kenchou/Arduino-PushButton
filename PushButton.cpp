#include "PushButton.h"

PushButton::PushButton(const int buttonPin, int buttonPinMode /*= INPUT*/)
{
	pushCount=0;
	debounceDelay = 50;
	pin = buttonPin;
	_pinMode = buttonPinMode;	

	pressedValue = buttonPinMode == INPUT_PULLUP ? LOW : HIGH;
	pinMode(buttonPin, buttonPinMode);
}

/**
 * set button state
 */
void PushButton::setState(boolean value)
{
	state = value;
}

boolean PushButton::getState()
{
	return state;
}

void setDebounceThreshold(unsigned long delay/* = 50*/)
{
	debounceDelay = delay;
}

/**
 * read actual value from pin
 * @return int HIGH|LOW
 */
boolean PushButton::read()
{
	int reading = digitalRead(pin);
	if (reading != _lastState) {
		// reset the debouncing timer
		lastDebounceTime = millis();
	} 
  
	if ((millis() - lastDebounceTime) > debounceDelay) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:
		_state = reading;
	}

	_lastState = reading;

	return _state;
}

boolean PushButton::readState()
{
	int readingState = read() == pressedValue;
	if (reading != state) {
		lastStateChangeTime = millis();
	}

	if ((millis() - lastStateChangeTime) > keepStateDelay) {
		state = readingState;
	}

	lastState = readingState;

	return state;
}

boolean isPressed()
{
	return read() == pressedValue;
}

boolean isReleased()
{
	return read() != pressedValue;
}