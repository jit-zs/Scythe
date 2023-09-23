
#include "pch.h"
#include <fstream>
#include <list>
#include <string>
#include <iostream>


using namespace winrt;
using namespace Windows::Foundation;

using std::string;
using std::getline;
using std::list;
using std::ifstream;
using std::cout;

export module loader;

namespace Scythe {
	export list<string> LoadScythe(string name) {
		ifstream fileReader(name);
		list<string> file = list<string>();
		string disposableReader;
		while (getline(fileReader, disposableReader)) {
			file.push_back(disposableReader);
		}
		return file;
	}
}