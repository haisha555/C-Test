#pragma once
#include <iostream>

class CustomArray
{
public:
	int* ArrayData{ nullptr };
	int MaxLength{ DefaultLength };
	int CurrentLength{0};

	const int DefaultLength = 2;
public:
	CustomArray() { ArrayData = (int*)malloc(sizeof(int) * DefaultLength); }
	~CustomArray() { free(ArrayData); }
	int get(int Index) { 
		if (Index >= CurrentLength)
			return -1;
		return ArrayData[Index]; 
	}
	void reserve(int len) {
		if (len <= MaxLength)
			return;
		MaxLength = len;
		ArrayData = (int*)realloc(ArrayData, sizeof(int) * MaxLength);
	}
	void push(int Value) {
		if (CurrentLength == MaxLength)
			reserve(MaxLength + DefaultLength);
		ArrayData[CurrentLength++] = Value;
	}
	void insert(int Index, int Value) {
		if (Index > MaxLength)
			return;
		push(ArrayData[CurrentLength - 1]);
		for (int i = CurrentLength - 1; i > Index; i--)
		{
			ArrayData[i] = ArrayData[i - 1];
		}
		ArrayData[Index] = Value;
	}
	bool remove(int Index) {
		if (Index < 0 || Index >= CurrentLength)
			return false;
		for (int i = Index + 1; i < CurrentLength; i++)
		{
			ArrayData[i - 1] = ArrayData[i];
		}
		return true;
	}
	void Pop() {
		remove(CurrentLength - 1);
	}
	void clear() {
		CurrentLength = 0;
	}
	int findIndex(int value) {
		for (int i = 0; i < CurrentLength; ++i) {
			if (ArrayData[i] == value)
			{
				return i;
			}
		}
		return -1;
	}
};

