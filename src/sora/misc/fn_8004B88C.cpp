#include <types.h>
#pragma force_active on

extern "C" int fn_8004B88C(void* arg0) {
    int field = *reinterpret_cast<int*>(arg0);
    if (field == 1) {
        return *reinterpret_cast<u16*>(static_cast<char*>(arg0) + 0x30) - 1;
    }
    if (field == 2) {
        return *reinterpret_cast<u16*>(static_cast<char*>(arg0) + 0x30);
    }
    return -1;
}
