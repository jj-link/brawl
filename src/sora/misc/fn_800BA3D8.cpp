#include <types.h>
#pragma force_active on

extern "C" int fn_800BA3D8(void* arg0) {
    u8 v = *(u8*)((char*)arg0 + 4);
    if (v == 0xFF) {
        return 0xF0;
    }
    int i;
    for (i = 0; i < 8; i++) {
        if (v & (1 << i)) break;
    }
    if (i >= 8) {
        return -1;
    }
    return i;
}
