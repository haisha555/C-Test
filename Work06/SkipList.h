#pragma once
#include "SkipListNode.h"
#include <math.h>

using namespace std;

class SkipList
{
public:
	SkipListNode* Head;
	int Level;
	int (*RandomLevel)();
	SkipList(int (*ramdomLevel)()) : RandomLevel(ramdomLevel), Level(0) { Head = new SkipListNode(); }

	bool Search(int Target) {
		SkipListNode* cur = Head;
		for (int i = Level - 1; i >= 0; i--) {
			while (cur->Nodes[i] != nullptr && cur->Nodes[i]->Value < Target) {
				cur = cur->Nodes[i];
			}
		}
		cur = cur->Nodes[0];
		return cur != nullptr &&cur->Value == Target;
	}

	void Add(int value) {
		int AddLevelNum = RandomLevel();
		std::vector<SkipListNode*> AddLevels(AddLevelNum, Head);
		SkipListNode* Cur = Head;
		for (int i = AddLevelNum - 1; i >= 0; i--) {
			while (Cur->Nodes[i] != nullptr && Cur->Value < value) {
				Cur = Cur->Nodes[i];
			}
			AddLevels[i] = Cur;
		}

		Level = Level > AddLevelNum ? Level : AddLevelNum;

		SkipListNode* AddNode = new SkipListNode(value, AddLevelNum);

		for (int i = 0; i < AddLevelNum; i++) {
			AddNode->Nodes[i] = AddLevels[i]->Nodes[i];
			AddLevels[i]->Nodes[i] = AddNode;
		}
	}

	bool Erase(int value) {
		std::vector<SkipListNode*> EraseLevels(Level, Head);
		SkipListNode* Cur = Head;
		for (int i = Level - 1; i >= 0; i--) {
			while (Cur->Nodes[i] != nullptr && Cur->Nodes[i]->Value < value) {
				Cur = Cur->Nodes[i];
			}
			EraseLevels[i] = Cur;
		}
		Cur = Cur->Nodes[0];
		if (!Cur || Cur->Value != value) return false;
		for (int i = 0; i < Level; i++) {
			if (EraseLevels[i]->Nodes[i] != Cur) break;
			EraseLevels[i]->Nodes[i] = Cur->Nodes[i];
		}
		delete Cur;
		return true;
	}
};