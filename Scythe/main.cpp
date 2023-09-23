#include "pch.h"
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iterator> 
#include <vector>
import loader;
import Lexer.cppm;
import ModTokens;
import Parser.cppm;
import ScyVar.cppm;

using namespace winrt;
using namespace Windows::Foundation;


using std::string;
using std::getline;
using std::list;
using std::ifstream;
using std::cout;
using std::isalnum;
using std::pair;
using std::ostream;
using std::vector;

using namespace Scythe;
vector<pair<string, string>> varNames;// First is name second is type

vector<ScyVar<int>>      intData;
vector<ScyVar<float>>    floatData;
vector<ScyVar<double>>   doubleData;
vector<ScyVar<string>>   stringData;
vector<ScyVar<bool>>     boolData;
vector<ScyVar<char>>     charData;

/*
vector<ScyVar<int>[]>    intArrData;
vector<ScyVar<float>[]>  floatArrData;
vector<ScyVar<double>[]> doubleArrData;
vector<ScyVar<string>[]> stringArrData;
vector<ScyVar<bool>[]>   boolArrData;
vector<ScyVar<char>[]>   charArrData;
*/ 
int main()
{
	list<string> file = Scythe::LoadScythe("Main.scythe");
	for (string s : file) {
		const char* cchar = s.data();// Current line in chars
		string currentWord = string();
		bool symbolMode = false;// Does not effect anything as of current
		vector<pair<Tokens, string>> tokens;
		for (int i = 0; i < s.length(); ++i) { // Cycles through chars in line
			//cout << cchar[i];
			if (!isalnum(cchar[i]) && *cchar != '_' && symbolMode == false) {
				tokens.push_back(Lex(currentWord));
				//cout << currentWord;
				currentWord = "";
				if (cchar[i] != ' ')
				{
					currentWord += cchar[i];
					symbolMode = true;
				}
			}
			else if (isalnum(cchar[i]) && *cchar != '_' && symbolMode == true) {
				tokens.push_back(Lex(currentWord));
				//cout << currentWord;
				currentWord = "";
				if (cchar[i] != ' ')
				{
					currentWord += cchar[i];
					symbolMode = false;
				}
			}
			else {
				currentWord += cchar[i];
			}
			if (i == s.length() - 1) {
				tokens.push_back(Lex(currentWord));
				//cout << currentWord;
			}
		}
		for (pair< Tokens, string > li : tokens) {
			cout << li.second << BR;
		}
		cout << BR;
	}
	return 0;
}
