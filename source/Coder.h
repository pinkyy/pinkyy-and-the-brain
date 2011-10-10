#pragma once

class Coder
{
	private:
		int length;
		uint32_t* data;
	public:
		Coder(int length);	//allocate mem
		~Coder(void);	//free mem
};
