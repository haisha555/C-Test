#pragma once
#include <iostream>

template<typename T>
struct Node {
	T Value;
	Node* Next;
	Node* Last;
};

template<typename T>
class CustomList
{
public:
	Node<T>* VirtualHead;
	Node<T>* VirtualEnd;
	CustomList() {
		VirtualHead = (Node<T>*)malloc(sizeof(Node<T>));
		VirtualEnd = (Node<T>*)malloc(sizeof(Node<T>));
		VirtualHead->Next = VirtualEnd;
		VirtualHead->Last = nullptr;
		VirtualEnd->Next = nullptr;
		VirtualEnd->Last = VirtualHead;
	};
	~CustomList() {
		while (VirtualHead) {
			Node<T>* Temp = VirtualHead;
			VirtualHead = VirtualHead->Next;
			free(Temp);
		}
	};

	Node<T>* GetHead() {
		return VirtualHead->Next == VirtualEnd ? nullptr : VirtualHead->Next;
	}

	Node<T>* Push(T Value) {
		Node<T>* Temp = VirtualHead;
		while (Temp->Next) {
			Temp = Temp->Next;
		}

		Node<T>* NewNode = (Node<T>*)malloc(sizeof(Node<T>));
		NewNode->Value = Value;
		NewNode->Next = nullptr;
		NewNode->Last = Temp;
		Temp->Next = NewNode;

		return NewNode;
	};

	Node<T>* Insert(Node<T>* node, T Value) {
		Node<T>* Temp = VirtualHead;
		while (Temp) {
			if (Temp = node)
			{
				Node<T>* NewNode = (Node<T>*)malloc(sizeof(Node<T>));
				NewNode->Value = Value;
				NewNode->Last = Temp->Last;
				Temp->Last->Next = NewNode;
				NewNode->Next = Temp;
				Temp->Last = NewNode;
				return NewNode;

			}
			Temp = Temp->Next;
		}
		return nullptr;
	};

	Node<T>* Find(int Value)
	{
		Node<T>* Temp = VirtualHead;
		while (Temp) {
			if (Temp->Value == Value)
				return Temp;
			Temp = Temp->Next;
		}
		return nullptr;
	}

	void Remove(Node<T>* node) {
		Node<T>* Temp = VirtualHead;
		while (Temp) {
			if (Temp == node)
			{
				Temp->Last->Next = Temp->Next;
				Temp->Next->Last = Temp->Last;
				free(Temp);
				return;
			}
			Temp = Temp->Next;
		}
	}

	void PopAll() {
		Node<T>* Temp = VirtualHead->Next;
		while (Temp != VirtualEnd) {
			free(Temp);
			VirtualHead = VirtualHead->Next;
		}
		VirtualHead->Next = VirtualEnd;
		VirtualEnd->Last = VirtualHead;
	}
};