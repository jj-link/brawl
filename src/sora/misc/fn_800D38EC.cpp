#include <types.h>
#pragma force_active on

extern "C" u8 fn_800C851C(void);

struct S {
    u8 pad[0xC9];
    u8 f : 4;
    u8 g : 4;
};

extern "C" void fn_800D38EC(char* base, s32 idx, s32 val) {
    u8 n = fn_800C851C();
    if (n == 0xFF) {
        n = 4;
    }
    S* p = (S*)(base + n * 0x218);
    p->f = (p->f & ~(1 << idx)) | (val << idx);
}
