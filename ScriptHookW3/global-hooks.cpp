#include "global-hooks.h"
#include "global-funcs.h"
#include "logger.h"
#include <string>

// Initialize global objects
DEFX64HOOK(w3::checkSameType);
DEFX64HOOK(w3::register_math_functions);
DEFX64HOOK(w3::CName_set);

// These are not hooked, we just get a pointer to them and use that
DEFX64FUNC(w3::registerGlobalFunc);
DEFX64FUNC(w3::getFunctionMapper);
DEFX64FUNC(w3::CRTTISystem_registerGlobalFunc);

w3::CRTTISystem* w3::global_rtti_system;

bool w3::checkSameType(void* type1, void* type2) {
	return true;
}

void w3::register_math_functions() {
	w3::register_math_functions_orig();
	
	// Register custom functions
	w3::CName name;
	w3::CName_set_orig(&name, L"exampleFunction");
	void* unknown = w3::getFunctionMapper_orig(0xC0, 0x10, 0x10 + 0x07);
	void* func_mapping = w3::registerGlobalFunc_orig(unknown, &name, &shw3::exampleFunction);
	w3::CRTTISystem_registerGlobalFunc_orig(w3::global_rtti_system, func_mapping);
}

void w3::CName_set(const CName* self, wchar_t const * name) {
	w3::CName_set_orig(self, name);
	if (name) {
		std::wstring ws(name);
		std::string str(ws.begin(), ws.end());
		LOG(LL_NFO, "CName set: ", str);
	} else {
		LOG(LL_NFO, "CName set: <null>");
	}
}