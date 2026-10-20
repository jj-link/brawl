#include <types.h>
#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void fn_27_6FF80(void*, u32);
void fn_27_6FEA8(void*);
}

extern "C" void fn_27_1452B4(void* self, u32 arg) {
    u8* b = (u8*)self;
    b[0x8] = 0;
    b[0x10] = 0;
    u32* w = (u32*)(b + 0x28);
    if (*w) {
        free__13gfHeapManagerFPv((void*)*w);
        *w = 0;
    }
    *(s32*)(b + 0x2c) = -1;
    b[0x30] = 0;
    fn_27_6FF80(b + 0x1c, arg);
    fn_27_6FEA8(b + 0x1c);
}
