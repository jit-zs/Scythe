#include "pch.h"
#include <list>
import ModTokens;

using std::string;
using std::list;
export module AST.cppm;
export namespace Scythe::AST {
	/// <summary>
	/// Do not create an instance of this class, it is made for AST nodes to inherit from and nothing else
	/// </summary>
	class Node {
	protected:
		Tokens node = NILL;
		Node(){
			node = NILL;
		}
	};
	class Name : public Node {
		
	};
	class Int : public Node {
		Name subNode;
		Int() {
			node = INT;
			subNode = Name();
		}
	};
}