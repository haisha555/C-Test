#pragma once
#include <iostream>

class CustomString
{
private:
	
public:
	char* CustomChars = nullptr;
	~CustomString();
	CustomString();
	CustomString(const char* InChars);
	CustomString(CustomString& Other);
	CustomString(CustomString&& Other);
	CustomString& operator=(const char* InChars);
	int len();
	CustomString sub(int IndexStart, int IndexEnd);
	void append(const char* InChars);
	bool operator==(CustomString& InCustomString);
	int find(const char* InChars);
	CustomString* split(const char* InChars);
};
