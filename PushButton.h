#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

class PushButton
{
	public:
		const int pin;
		bool state;	//button state: true/false
		int pressedValue;	//a value HIGH or LOW to indicate Pressed state
		unsigned int pushCount;
	protected:
		unsigned int lastReadingState;	//last state read from pin
		unsigned long lastDebounceTime;  // the last time the output pin was toggled
		unsigned long debounceDelay;
	public:
		PushButton(int buttonPin, int buttonPinMode = INPUT);
		/**
		 * set a value to check press or release
		 * @param bool value
		 */
		void setPressedValue(bool value = HIGH);
		/**
		 * set debounce mode
		 * @param bool debounce
		 */
		void setDebounceMode(bool debounce);
		void setDebounceThreshold(unsigned long delay);
		void setInitialState(int value);
		/**
		 * read pin state
		 * @return bool
		 */
		bool read();
		bool isPress();
		bool getState();
		void setState(bool state);
};

#endif
