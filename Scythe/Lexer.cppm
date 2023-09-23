#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include "pch.h"
import ModTokens;
import myShit;
import MyString.cppm;


using std::string;
using std::pair;
using std::make_pair;
using std::isalnum;
using namespace MyShit;


export module Lexer.cppm;
namespace Scythe {
	export pair<Tokens, string> Lex(string word) {
		if (isnumber(word))
			return make_pair(NUMBER, word);
		else if (word == "int")
			return make_pair(INT, "int");
		else if (word == "string")
			return make_pair(STRING, "string");
		else if (word == "=")
			return make_pair(EQUALS_SET, "equals");
		else
			return make_pair(NAME, word);
	}
}
