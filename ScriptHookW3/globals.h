#pragma once
#include <Windows.h>
#include <cstdint>
#include <memory>
#include "PolyHook.h"

#define DEFX64HOOK(name,ret,sig) \
ret name ## sig; \
typedef ret(*name ## _type) ## sig; \
extern name ## _type name ## _orig; \
extern std::shared_ptr<PLH::X64Detour> name ## _hook;

namespace w3 {
	DEFX64HOOK(checkSameType, bool, (void* type1, void* type2));
}