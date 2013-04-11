#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

class PushButton
{
	public:
		int pin;
		bool state;	//button state: true/false
		int pressedValue;	//a value HIGH or LOW to indicate Pressed state
		unsigned int pushCount;
	protected:
		int _pinMode;
		unsigned int lastReadingState;	//last state read from pin
		unsigned long lastDebounceTime;  // the last time the output pin was toggled
		unsigned long debounceDelay;
	public:
		/**
		 * @param int buttonPin
		 * @param int buttonPinMode INPUT or INPUT_PULLUP
		 */
		PushButton(int buttonPin, int buttonPinMode = INPUT);
		/**
		 * set a value to check press or release
		 * @param bool value
		 */
		void setPressedValue(bool value);
		bool getPressedValue();
		/**
		 * set debounce mode
		 * @param bool debounce
		 */
		void setDebounceMode(bool debounce);
		void setDebounceThreshold(unsigned long delay = 50);
		/**
		 * set button state
		 * default released
		 */
		void setState(bool value);
		bool getState();
		/**
		 * read pin state
		 * @return bool
		 */
		bool read();
		bool isPressed();
		bool isReleased();
};

#endif
