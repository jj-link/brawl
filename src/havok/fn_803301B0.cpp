#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_803318EC(u8* self, s32 a);
void fn_803318F8(u8* self, u32 a, s32** b);
void fn_80331980(u8* self, s32 a, s32 b);
}

extern "C" void fn_803301B0(u8* self, u32 arg1, s32* arg2) {
    s32* p = arg2;
    s32 cur = *arg2;
    if (cur != 0) {
        s32 idx = fn_803318EC(self + 0xc, cur);
        while (idx != -1) {
            u32* node = (u32*)(*(u8**)(self + 0xc) + idx * 8);
            if (node[0] == (u32)p) {
                if (arg1 == (u32)cur) {
                    return;
                }
                fn_80331980(self + 0xc, cur, idx);
                break;
            }
            idx = (s32)node[1];
        }
    }
    if (arg1 != 0) {
        fn_803318F8(self + 0xc, arg1, &p);
    }
    *p = (s32)arg1;
}
