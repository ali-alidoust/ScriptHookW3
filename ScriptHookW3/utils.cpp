#include "utils.h"
#include <stdint.h>
void* shw3::extractPointer(void* base, int ptroffset)
{
	intptr_t offset = (intptr_t)*(int32_t*)(((char*)base) + ptroffset);
	return (void*)(offset + ((char*)base + ptroffset + 4));
}
