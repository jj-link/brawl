#include <types.h>
#pragma force_active on

extern "C" void fn_801B9390(void* arg);

extern "C" void fn_801D1C3C(u8* arg0, void* arg1) {
    s32 off;
    u8* p;
    s32 i;
    s32 j;

    i = 0;
    off = 0;
    while (i < *(s32*)(arg0 + 0xA0)) {
        p = arg0 + off;
        j = 0;
        while (j < *(s32*)(arg0 + 0x9C)) {
            void* v = *(void**)(p + 0xC);
            if (v != 0) {
                fn_801B9390(v);
            }
            p += 0x10;
            j++;
        }
        off += 4;
        i++;
    }
}
