#pragma once
#include <vector>

struct SkipListNode
{
	int Value;
	std::vector<SkipListNode*> Nodes;
	SkipListNode(int value = -1, int NodeNumber = 32) : Value(value), Nodes(NodeNumber, nullptr) {

	}
};