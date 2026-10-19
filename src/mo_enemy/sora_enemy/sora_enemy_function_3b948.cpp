#include <types.h>
#pragma force_active on

extern "C" {
void* fn_41_3B948(void* p, s32 n) {
    if (n == 5) {
        return (char*)p + 0xfc;
    }
    if (n == 4) {
        return (char*)p + 0xd0;
    }
    if (n == 3) {
        return (char*)p + 0xa4;
    }
    if (n == 2) {
        return (char*)p + 0x78;
    }
    if (n == 1) {
        return (char*)p + 0x4c;
    }
    if (n == 0) {
        return (char*)p + 0x20;
    }
    return 0;
}
}
