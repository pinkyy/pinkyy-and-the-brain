#pragma once

class Coder
{
	private:
		int length;
		uint8_t* data;
	public:
		Coder(int length);	//allocate mem
		~Coder(void);	//free mem
};