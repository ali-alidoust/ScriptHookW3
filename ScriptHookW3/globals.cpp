#include "globals.h"

// Initialize global objects
std::shared_ptr<PLH::X64Detour> w3::checkSameType_hook(new PLH::X64Detour);
w3::checkSameType_type w3::checkSameType_orig;

bool w3::checkSameType(void* type1, void* type2) {
	return true;
}