// ScriptHookW3.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "main.h"
#include "yara-helper.h"
#include "logger.h"
#include "globals.h"
#include "hook.h"

void shw3::Main::initialize()
{
	std::shared_ptr<YaraHelper> yara;
	yara.reset(new YaraHelper());
	yara->initialize();

	void* check_same_type_ptr = nullptr;
	yara->addEntry("yara_check_same_type_function", yara_check_same_type_function, &check_same_type_ptr);

	yara->performScan();

	NOT_NULL(check_same_type_ptr, "Could not find the address for CheckSameType() function");

	REQUIRE(hookX64Function(check_same_type_ptr, &w3::checkSameType, &w3::checkSameType_orig, w3::checkSameType_hook), "Failed to hook CheckSameType() function.");

}
