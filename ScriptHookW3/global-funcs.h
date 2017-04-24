#pragma once

#include "IScriptable.h"
#include "CScriptStackFrame.h"
namespace shw3 {
	void exampleFunction(w3::IScriptable* pThis, w3::CScriptStackFrame& stackFrame, void* result) {
		stackFrame.unk_0x30++;
		*(int*)result = 12345678;
	}
}