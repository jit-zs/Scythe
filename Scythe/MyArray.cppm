#include "pch.h"
export module myShit;
export namespace MyShit {;
	class MyArray {
	public:
		template <typename T>
		static bool ArrayContains(T sampleArray[], T item) {
			for (int i = 0; i < sizeof(sampleArray); ++i) {
				if (sampleArray[i] == item) {
					return true;
				}
			}
			return false;
		}
	};
}
