#include <types.h>
#pragma force_active on

extern "C" int fn_800C6E10(void* arg0) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(arg0) + 0x350) = 1;
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(arg0) + 0x110);
}
