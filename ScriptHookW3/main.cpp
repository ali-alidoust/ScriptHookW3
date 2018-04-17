#include "stdafx.h"
#include "main.h"
#include "yara-helper.h"
#include "logger.h"
#include "global-hooks.h"
#include "hook.h"
#include "w3types.h"
#include "utils.h"
#include <iostream>

void shw3::Main::initialize()
{
	LOG(LogLevel::LL_NFO,"ScriptHookW3 Loaded!")
	std::shared_ptr<YaraHelper> yara;
	yara.reset(new YaraHelper());
	yara->initialize();

	void* check_same_type_ptr = nullptr;
	void* cname_set_ptr = nullptr;
	void* cname_set_tstring_ptr = nullptr;
	void* get_function_mapper_base_addr = nullptr;
	void* register_global_func_ptr = nullptr;
	void* crtti_register_global_func_ptr = nullptr;
	void* crttisystem_pointer_base_ptr = nullptr;
	yara->addEntry("yara_check_same_type_function", yara_check_same_type_function, &check_same_type_ptr);
	yara->addEntry("cname_set_ptr", yara_cname_set_function, &cname_set_ptr);
	yara->addEntry("yara_register_global_function", yara_register_global_function, &register_global_func_ptr);
	yara->addEntry("yara_get_function_mapper_34", yara_get_function_mapper_34, &get_function_mapper_base_addr);
	yara->addEntry("yara_crttisystem_register_global_func", yara_crttisystem_register_global_func, &crtti_register_global_func_ptr);
	yara->addEntry("yara_crttisystem_pointer_base_22", yara_crttisystem_pointer_base_22, &crttisystem_pointer_base_ptr);
	yara->addEntry("yara_cname_set_function_tstring", yara_cname_set_function_tstring, &cname_set_tstring_ptr);

	yara->performScan();

	NOT_NULL(check_same_type_ptr, "Could not find the address for CheckSameType() function");
	NOT_NULL(cname_set_ptr, "Failed to get the address for CName::set(wchar_t const *) function");
	NOT_NULL(cname_set_tstring_ptr, "Failed to get the address for CName::set(TString<wchar_t> const &) function")
	NOT_NULL(register_global_func_ptr, "Failed to get the address for registerGlobalFunc() function");
	NOT_NULL(get_function_mapper_base_addr, "Failed to get the address for getFunctionMapper() function");
	NOT_NULL(crtti_register_global_func_ptr, "Failed to get the address for CRTTISystem::registerGlobalFunc() function");
	NOT_NULL(crttisystem_pointer_base_ptr, "Failed to get the address for global CRTTISystem instance");

	
	// w3::CName_set_orig = (w3::CName_set_type)cname_set_ptr;
	w3::registerGlobalFunc_orig = (w3::registerGlobalFunc_type)register_global_func_ptr;
	w3::CRTTISystem_registerGlobalFunc_orig = (w3::CRTTISystem_registerGlobalFunc_type)crtti_register_global_func_ptr;

	w3::getFunctionMapper_orig = (w3::getFunctionMapper_type)shw3::extractPointer(get_function_mapper_base_addr, 34);
	w3::global_rtti_system = *(w3::CRTTISystem**)shw3::extractPointer(crttisystem_pointer_base_ptr, 22);

	this->register_global_functions();
	
	REQUIRE(HOOKX64(check_same_type_ptr, w3::checkSameType), "Failed to hook CheckSameType() function.");
	REQUIRE(HOOKX64(get_function_mapper_base_addr, w3::register_math_functions), "Failed to hook register_math_functions() function.");
	REQUIRE(HOOKX64(cname_set_ptr, w3::CName_set), "Failed to hook CName::set(TString<wchar_t> const &) function");
}

void shw3::Main::register_global_functions()
{
	
}
