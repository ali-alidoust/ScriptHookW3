#pragma once
#include <stdint.h>

namespace w3 {
	struct CName {
		uint32_t pool_index;
		CName() : pool_index(0) {}
	};
}