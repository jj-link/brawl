#pragma force_active on
#include <types.h>

extern "C" u8 fn_800C851C(void);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern int lbl_805A03A8;

extern "C" void fn_800CA5F8(u8* self, u32 arg1, u8 arg2) {
    u8 idx = fn_800C851C();
    if (idx == 0xFF) {
        idx = 4;
    }
    u8* e = self + arg1 * 8;
    if (e[0x4C] == idx) {
        u32 r30 = e[0x4D];
        u8 idx2 = fn_800C851C();
        if (idx2 == 0xFF) {
            idx2 = 4;
        }
        u8* p = self + idx2 * 0x218;
        p[r30 * 8 + 0xAC] = arg2;
        u8 idx3 = fn_800C851C();
        if (idx3 == 0xFF) {
            idx3 = 4;
        }
        u8* q = self + idx3 * 0x218;
        q[0xC6] |= 1;
        fn_800D0AE0(self, q);
        fn_80145B98(lbl_805A03A8, 0xFE);
    }
}
