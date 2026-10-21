#include <types.h>
#pragma force_active on

extern "C" void fn_27_6FEB8(void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_27_6FF08(void*);
extern s32 lbl_27_rodata_146C;

struct Flags {
    u8 a : 7;
    u8 b : 1;
};

extern "C" void fn_27_14178C(u8* self, s32 arg1, s32 unused, s32 arg3) {
    if (self[0x0C] == 0) {
        Flags* fl = (Flags*)(self + 0x37);
        if (arg1 != 0) {
            fn_27_6FF08(self + 0x20);
        } else {
            fn_27_6FEB8(self + 0x20, lbl_27_rodata_146C, arg3, 0, 0, 0, 0xFF, 1);
        }
        self[0x14] = 3;
        *(s32*)(self + 0x28) = arg3;
        self[0x35] = 0;
        fl->a = 0xF;
        *(s32*)(self + 0x1078) = -1;
    }
    self[0x0C]++;
}
