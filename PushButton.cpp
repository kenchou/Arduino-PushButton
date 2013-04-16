#include "PushButton.h"

PushButton::PushButton(const int buttonPin, int buttonPinMode /*= INPUT*/)
{
	pushCount=0;
	debounceDelay = 50;
	pin = buttonPin;
	_pinMode = buttonPinMode;

	pinMode(buttonPin, buttonPinMode);
	setPressedValue(buttonPinMode == INPUT_PULLUP ? LOW : HIGH);
}

/**
 * set a state value as pressd state
 */
void PushButton::setPressedValue(boolean value)
{
	pressedValue = value;
}

boolean PushButton::getPressedValue()
{
	return pressedValue;
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

/**
 * set debounce mode
 * @param boolean debounce
 */
void setDebounceMode(boolean debounce)
{
}

void setDebounceThreshold(unsigned long delay = 50)
{
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

boolean isPressed()
{
}

boolean isReleased()
{
}