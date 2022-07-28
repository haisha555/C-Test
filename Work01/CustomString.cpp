#include "CustomString.h"
#include <string.h>

CustomString::~CustomString()
{
	delete[] CustomChars;
	CustomChars = nullptr;
}

CustomString::CustomString()
{
}

CustomString::CustomString(const char* InChars)
{
	int Length = strlen(InChars) + 1;

	CustomChars = new char[Length];

	memcpy(CustomChars, InChars, Length);

}

CustomString::CustomString(CustomString& Other)
{
	int Length = strlen(Other.CustomChars) + 1;

	CustomChars = new char[Length];

	memcpy(CustomChars, Other.CustomChars, Length);
}

CustomString::CustomString(CustomString&& Other) : CustomChars(Other.CustomChars)
{
	Other.CustomChars = nullptr;
}


CustomString& CustomString::operator=(const char* InChars)
{
	int Length = strlen(InChars) + 1;
	                                                                                                 
	CustomChars = new char[Length];

	memcpy(CustomChars, InChars, Length);

	return *this;
}

int CustomString::len()
{
	char* Head = CustomChars;
	int res = 0;
	while (*Head++ != '\0')
	{
		res++;
	}
	return res;
	delete Head;
}

CustomString CustomString::sub(int IndexStart, int IndexEnd)
{
	int len = IndexEnd - IndexStart + 1;

	char* Res = new char[len];

	const char* Head = Res;

	for (int i = IndexStart; i < IndexEnd; ++i)
	{
		*Res = CustomChars[i];
		Res++;
	}

	*Res = '\0';

	CustomString ResCustomString(std::move(CustomString(Head)));

	delete[] Head;

	return ResCustomString;
}

void CustomString::append(const char* InChars)
{
	int length = len() + strlen(InChars) + 1;

	char* Res = new char[length];

	memcpy(Res, CustomChars, len());

	memcpy(&Res[len()], InChars, strlen(InChars));

	Res[length - 1] = '\0';

	delete[] CustomChars;

	CustomChars = Res;
}

bool CustomString::operator==(CustomString& InCustomString) 
{
	if(len() != InCustomString.len())
		return false;
	for (int i = 0; i < len(); i++)
		if (CustomChars[i] != InCustomString.CustomChars[i])
			return false;
	return true;
}

int CustomString::find(const char* InChars)
{
	for (int i = 0; i < len(); i++)
	{
		for (int j = 0; j < strlen(InChars); j++)
		{
			if (CustomChars[i + j] == InChars[j])
			{
				if (j == strlen(InChars) - 1)
					return i;
			}
			else
				break;
		}
	}
	return -1;
}

CustomString* CustomString::split(const char* InChars)
{
	int SplitCoount = 0;

	for (int i = 0; i < len(); i++)
	{
		for (int j = 0; j < strlen(InChars); j++)
		{
			if (CustomChars[i + j] == InChars[j])
			{
				if (j == strlen(InChars) - 1)
				{
					SplitCoount++;
				}
			}
			else
				break;
		}
	}

	int* SplitFrontIndex = new int[SplitCoount + 2];
	SplitFrontIndex[0] = 0;
	SplitFrontIndex[SplitCoount + 1] = len();

	SplitCoount = 1;

	int length = strlen(InChars);

	for (int i = 0; i < len(); i++)
	{
		for (int j = 0; j < strlen(InChars); j++)
		{
			if (CustomChars[i + j] == InChars[j])
			{
				if (j == strlen(InChars) - 1)
				{
					SplitFrontIndex[SplitCoount] = i;
					SplitCoount++;
				}
			}
			else
				break;
		}
	}

	// CustomString* Res = (CustomString*)malloc((SplitCoount + 1) * sizeof(CustomString));

	CustomString* Res = new CustomString[SplitCoount + 1]();
	for(int i = 0; i < SplitCoount; i++)
	{
 		CustomString SubString = sub(i == 0 ? 0 :SplitFrontIndex[i] + length, i == SplitCoount - 1 ? len() : SplitFrontIndex[i + 1]);

		//delete Res[i]

		Res[i] = SubString.CustomChars;
	}

	delete SplitFrontIndex;

	return Res;
}
