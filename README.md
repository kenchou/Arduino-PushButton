Arduino-PushButton
==================

功能：
读取状态：
* 按下时返回 press 状态
* 释放时返回 release 状态
* 长按释放后保持 press 状态
* 再次长按释放后保持 release 状态

example:

	PushButton button1(12);
	const StatePin=13;
	
	void setup()
	{
	 pinMode(StatePin, OUTPUT);
	}

	void loop()
	{
		if (button1.isPressed()) {
			digitWrite(StatePin, HIGH);
		} else {
			digitWrite(StatePin, LOW);
		}
	}
 