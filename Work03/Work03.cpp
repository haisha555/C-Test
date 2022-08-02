#include "CustomRingBuffer.h"
#include <vld.h>

int main()
{
	/*CustomRingBuffer buffer(9);
	buffer.Push(1);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(2);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(3);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(4);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(5);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(6);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(7);
	std::cout << buffer.Pop() << std::endl;
	buffer.Push(8);
	buffer.Push(9);


	buffer.Push(10);
	buffer.Push(11);
	int n = 4;
	while (n--) {
		std::cout << buffer.Pop() << std::endl;
	}*/


	int initSize = 256;
	const char* data = "123456789";
	auto buffer = new CustomRingBuffer(initSize);
	srand(time(NULL));
	int length = strlen(data) + 1;
	for (int ii = 0; ii < 10; ii++)
	{
		int pushCount = rand() % 10;

		for (int jj = 0; jj < pushCount; jj++) buffer ->Push(data[jj] - '0');    // 要支持自动扩容

		//char out[128];
		int popCount = rand() % 10;
		for (int jj = 0; jj < popCount; jj++) std::cout << buffer->Pop() << std::endl;   // 要支持自动缩容
	}
	delete buffer;
}

