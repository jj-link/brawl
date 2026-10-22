#pragma force_active on
#include <types.h>

extern u8* fn_8022EFF8(int);
extern void fn_80242908(void* p);

s32 fn_80245D40(void) {
    u8* p;

    p = fn_8022EFF8(2);
    if (p == NULL) {
        return 0;
    }
    *(s16*)(p + 0x2) = 3;
    *(s16*)(p + 0x4) = 0;
    p[0x8] = 3;
    p[0x9] = 0xC;
    p[0xA] = 0;
    fn_80242908(p);
    return 1;
}
