#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

class PushButton
{
	public:
		boolean state;
		int pressedValue;	//a value HIGH or LOW to indicate Pressed state
		unsigned int pushCount;
	protected:
		int pin;
		int _pinMode;
		unsigned int _state;	//button state: true/false
		unsigned int _lastState;	//last state read from pin
		unsigned long lastDebounceTime;  // the last time the output pin was toggled
		unsigned long debounceDelay;
	public:
		/**
		 * @param int buttonPin
		 * @param int buttonPinMode INPUT or INPUT_PULLUP
		 */
		PushButton(const int buttonPin, int buttonPinMode = INPUT);
		/**
		 * set a value to check press or release
		 * @param boolean value
		 */
		void setPressedValue(boolean value);
		boolean getPressedValue();
		/**
		 * set debounce mode
		 * @param boolean debounce
		 */
		void setDebounceMode(boolean debounce);
		void setDebounceThreshold(unsigned long delay = 50);
		/**
		 * set button state
		 * default released
		 */
		void setState(boolean value);
		boolean getState();
		/**
		 * read pin state
		 * @return boolean
		 */
		boolean read();
		boolean isPressed();
		boolean isReleased();
};

#endif
