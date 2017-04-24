#pragma once

#include "IScriptable.h"
#include "CScriptStackFrame.h"
namespace shw3 {
	void exampleFunction(w3::IScriptable* pThis, w3::CScriptStackFrame& stackFrame, void* result) {
		*((int64_t*)((char*)(&stackFrame) + 0x30)) = *((int64_t*)((char*)(&stackFrame) + 0x30)) + 1;
		*(int*)result = 12345678;
	}
}