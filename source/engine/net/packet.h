#pragma once
#include <SDL/SDL_endian.h>
#include <cstring>

class NetPacket
{
private:
	const int length;
	uint8_t* const data;
public:
	static NetPacket* extract(int* size, const uint8_t* buffer)
	{
		if (*size < 4) return NULL;
		uint32_t length = *(uint32_t*)buffer;
		length = SDL_Swap32(length);
		if (*size < (length+4)) return NULL;
		uint8_t* clone = new uint8_t[length];
		memcpy(clone, buffer, length);
		*size -= length+4;
		return new NetPacket(length, clone);
	}
	NetPacket(int length, uint8_t* data) : length(length), data(data) {}
	~NetPacket() { delete data; }
	
};
