#include "pch.h"
#include <ctype.h>
#include <string>
using std::string;
export module MyString.cppm;
export namespace Scythe
{
	bool isnumber(string word) {
		for (int i = 0; i < word.length(); ++i)
			if (isalpha(word.data()[i]))
				return false;
		return true;
	}
}
