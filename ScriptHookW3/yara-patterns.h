#pragma once

#include <string>

// const std::string yara_get_render_time_base_function = "48 83 EC 28 48 8B 01 FF 50 ?? 8B C8 48 83 C4 28 E9 ?? ?? ?? ??";
const std::string yara_check_same_type_function = "48 89 5C 24 08 57 48 83 EC ?? 49 8B F8 48 8B DA 49 3B D0 74 ?? 48 8B 03 48 8B CB";
const std::string yara_cname_set_function = "48 89 5C 24 08 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 74 ?? 66 83 3A 00 74 ?? 45 33 C0";
const std::string yara_register_global_function = "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 33 F6 48 8D ?? ?? ?? ?? ?? 48 8B F9 48 89 01 48 89 71 08 8B 02 89 41 10 C7 41 14 03 00 00 00 48 89 71 18 48 89 71 20 89 71 28 48 89 71 2C 89 71 34 48 89 71 38 89 71 40 48 89 71 44 48 89 71 4C 48 83 C1 58 49 8B D8";
const std::string yara_get_function_mapper_34 = "40 55 53 57 48 8D AC 24 60 FF FF FF 48 81 EC A0 01 00 00 BA 10 00 00 00 B9 C0 00 00 00 44 8D 42 07 E8 ?? ?? ?? ??";
const std::string yara_crttisystem_constructor =  "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 60 33 F6 48 8B D9 48 83 C1 18 48 89 71 E8 89 71 F0 48 89 71 F8";
const std::string yara_crttisystem_register_global_func =  "48 89 54 24 10 48 83 EC 28 83 79 44 00 4C 8D 49 40 4C 8D 52 10";
const std::string yara_crttisystem_pointer_base_22 = "E8 77 DF 02 00 48 8D 0D ?? ?? ?? ?? 48 89 05 ?? ?? ?? ?? 48 8B 05 ?? ?? ?? ??";