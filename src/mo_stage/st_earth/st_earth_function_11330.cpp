#include <types.h>
#pragma force_active on

extern "C" void fn_66_11330(void *self) {
    int *p = reinterpret_cast<int*>(static_cast<char*>(self) + 0x8);
    *p |= 0x400000;
}
