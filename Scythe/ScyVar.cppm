#include "pch.h"
export module ScyVar.cppm;
export namespace Scythe {
	template <typename T>
	struct ScyVar {
		T var;
		T ptr varPtr;
		ScyVar(){
			varPtr = &var;
		}
	};
}