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
void PushButton::setPressedValue(bool value)
{
	pressedValue = value;
}

bool PushButton::getPressedValue()
{
	return pressedValue;
}

/**
 * set button state
 */
void PushButton::setState(bool value)
{
	state = value;
}

bool PushButton::getState()
{
	return state;
}

/**
 * set debounce mode
 * @param bool debounce
 */
void setDebounceMode(bool debounce)
{
}

void setDebounceThreshold(unsigned long delay = 50)
{
}

/**
 * read actual value from pin
 * @return int HIGH|LOW
 */
bool PushButton::read()
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

bool isPressed()
{
}

bool isReleased()
{
}