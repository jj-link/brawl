#include <types.h>
#pragma force_active on

extern "C" void* memset(void*, int, unsigned long);
extern "C" int randi__Fl(long);

extern "C" void fn_800555D8(u8* self, u8* out) {
    u8 buf[4];
    s32 best = -1;
    u8* p;
    s32 n;
    s32 i;
    s32 j;

    memset(buf, 0, 4);
    for (i = 0; i < 4; i++) {
        s32 a = 0x25 + i * 0x2AC;
        if (self[a] == 0) {
            if ((s32)self[a + 0xD] > best) {
                best = self[a + 0xD];
            }
        }
    }
    n = 0;
    p = buf;
    for (j = 0; j < 4; j++) {
        s32 a = 0x25 + j * 0x2AC;
        if (self[a] == 0) {
            if (best == (s32)self[a + 0xD]) {
                *p = (u8)j;
                n++;
                p++;
            }
        }
    }
    if (n != 0) {
        out[2] = buf[randi__Fl(n)];
    } else {
        ((s8*)out)[2] = -1;
    }
}
