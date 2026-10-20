#include <types.h>
#pragma force_active on
extern "C" {
void fn_801A12AC(s32 a);
void fn_801ACE24(s32 a);
void fn_2_8388(s32* p) {
    s32 v;
    s32 offset = 0;
    for (s32 i = 0; i < 2; i++) {
        s32* arr = (s32*)*(s32**)((char*)p + 0x40);
        v = *(s32*)((char*)arr + offset);
        if (v != 0) {
            fn_801A12AC(0x7ff);
            fn_801ACE24(v);
        }
        offset += 8;
    }
}
}
