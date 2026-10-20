#include <types.h>
#pragma force_active on

extern "C" int fn_27_CE4E8(void* self) {
    return *(int*)(reinterpret_cast<char*>(self) + 8) >> 27;
}
