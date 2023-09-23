#include "pch.h"
#include <iostream>

namespace MyShit {
	template<typename T>
	class ArrList {
	private: 
		struct ListNode {
			T var;
			ListNode* nextVar;
			ListNode(T value){
				var = value;
			}
		};
		ListNode ptr mCurrentVar;
	public:
		int length;	
	
		ListNode ptr anchor;
		ListNode ptr end;
	private:
		
	public:
		void add(T value) {
			ListNode ptr nnew = new ListNode(value);
			
			if (length == 0) {
				anchor->var = value;
				end = anchor;
				mCurrentVar = anchor;
			}
			end->nextVar = nnew;
			end = nnew;
			length++;
		}
		ArrList &operator[](int i){
			mCurrentVar = anchor;
			std::cout << "name" << BR;
			for (int i = 0; i < length; ++i) {
				mCurrentVar = mCurrentVar->nextVar;
			}
			return mCurrentVar;
		}
	};
}