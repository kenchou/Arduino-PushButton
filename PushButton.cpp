#include "PushButton.h"

PushButton::PushButton(int buttonPin, int buttonPinMode /*= INPUT*/)
{
	pushCount=0;
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
 * @return int HIGH|LOW
 */
bool PushButton::read()
{

}

bool isPressed()
{
}

bool isReleased()
{
}