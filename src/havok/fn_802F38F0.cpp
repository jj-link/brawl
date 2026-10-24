#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern "C" void fn_802FF49C(char* p, int arg1, float f1, float f2);

extern "C" void fn_802F38F0(char* self, int arg1, float f1, float f2) {
    u32 end;
    int off;
    int i;
    char* p;

    i = 0;
    off = 0;
    while (i < *(int*)(self + 0x4c)) {
        i++;
        p = *(char**)(*(char**)(self + 0x48) + off);
        off += 4;
        if (i == *(int*)(self + 0x4c)) {
            end = (u32)p + *(u32*)(self + 0x58);
        } else {
            end = (u32)p + *(u16*)(self + 0x5e);
        }
        while ((u32)p < end) {
            fn_802FF49C(p, arg1, f1, f2);
            p += *(u8*)(p + 3);
        }
    }
}
