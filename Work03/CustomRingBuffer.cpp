#include "CustomRingBuffer.h"

int Abs(int a, int b);

CustomRingBuffer::CustomRingBuffer(int Size) {
	BufferData = (int*)malloc(Size * sizeof(int));
	BufferSize = Size;
}

CustomRingBuffer::~CustomRingBuffer() {
	free(BufferData);
	BufferData = nullptr;
}

int CustomRingBuffer::Pop() {
	if (CurrentSize <= 0)
	{
		std::cout << "RingBuffer No Data!!" << std::endl;
		return -1;
	}
	int res = BufferData[PopIndex];
	PopIndex = (PopIndex + 1) % BufferSize;
	CurrentSize--;
	if (CurrentSize <= BufferSize / 3 && CurrentSize != 0)
	{
		int TargetBufferSize = (BufferSize + 1) / 2;
		int ReduceSize = BufferSize - PushIndex + 1;
		BufferSize = TargetBufferSize;
		if (PushIndex > PopIndex) {
			for (int i = PushIndex - 1; i >= PopIndex; i--) {
				BufferData[BufferSize - (PushIndex - i)] = BufferData[i];
				BufferData[i] = 0;
			}

			PopIndex = BufferSize - (PushIndex - PopIndex);
			PushIndex = BufferSize;
		}
		else
		{
			for (int i = BufferSize * 2 - 2; i >= PopIndex; i--) {
				BufferData[i - BufferSize + 1] = BufferData[i];
				BufferData[i] = 0;
			}
			PopIndex -= BufferSize - 1;
		}

		BufferData = (int*)realloc(BufferData, BufferSize * sizeof(int));
	}
	return res;
}

void CustomRingBuffer::Push(int Value) {
	if (CurrentSize >= BufferSize) {
		BufferSize *= 2;
		BufferData = (int*)realloc(BufferData, BufferSize*sizeof(int));
		if (PopIndex != 0) {
			PopIndex += BufferSize / 2;
			for (int i = PopIndex; i <= BufferSize / 2; i++) {
				BufferData[i + BufferSize / 2] = BufferData[i];
				BufferData[i] = 0;
			}
		}
	}
	if (PushIndex > BufferSize - 1)
		PushIndex = PushIndex % BufferSize;
	BufferData[PushIndex] = Value;
	PushIndex = PushIndex + 1;
	CurrentSize++;
}

//int Abs(int a, int b) {
//	int c = a + b;
//	return  c > 0 ? c : -c;
//}