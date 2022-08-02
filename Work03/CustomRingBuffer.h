#pragma once
#include <iostream>

class CustomRingBuffer
{
public:
	int* BufferData;
	int PushIndex{ 0 };
	int PopIndex{ 0 };
	int BufferSize { 0 };
	int CurrentSize{ 0 };
	CustomRingBuffer(int Size);
	~CustomRingBuffer();
	int Pop();
	void Push(int Value);
};

