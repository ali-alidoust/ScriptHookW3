#pragma once
#include <Windows.h>
#include <cstdint>
#include <memory>
#include "PolyHook.h"
#include "w3types.h"

#define DECX64HOOK(name,ret,sig) \
ret name ## sig; \
typedef ret(*name ## _type) ## sig; \
extern name ## _type name ## _orig; \
extern std::shared_ptr<PLH::X64Detour> name ## _hook;

#define DEFX64HOOK(fullname) \
std::shared_ptr<PLH::X64Detour> fullname ## _hook(new PLH::X64Detour); \
fullname ## _type fullname ## _orig;

#define DECX64FUNC(name, ret, sig) \
typedef ret(*name ## _type) ## sig; \
extern name ## _type name ## _orig;

#define DEFX64FUNC(fullname) \
fullname ## _type fullname ## _orig;

namespace w3 {
	DECX64HOOK(checkSameType, bool, (void* type1, void* type2));
	DECX64HOOK(register_math_functions, void, ());
	// DECX64HOOK(CRTTISystem_constructor, CRTTISystem*, ());

	DECX64FUNC(CName_set, void, (const CName* self, wchar_t const * name));
	DECX64FUNC(registerGlobalFunc, void*, (void* unknown, CName* name, void* func));
	DECX64FUNC(getFunctionMapper, void*, (int32_t a, int32_t b, int64_t c));
	DECX64FUNC(CRTTISystem_registerGlobalFunc, void, (CRTTISystem* rtti, void* func_mapping));

	extern CRTTISystem* global_rtti_system;
}