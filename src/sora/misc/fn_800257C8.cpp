#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_80494EE8[];

void fn_800257C8(s32 idx, s32 a, s32 b) {
    unsigned char* p = lbl_80494EE8 + idx * 104;
    unsigned char* q = p + (*(s32*)(p + 4) << 3);
    *(s32*)(q + 8) = a;
    *(s32*)(q + 12) = b;
    *(s32*)(p + 4) = *(s32*)(p + 4) + 1;
}
}
