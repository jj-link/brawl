#include <types.h>
#pragma force_active on
extern "C" u8 fn_800C8548();
extern "C" u8 fn_800C851C();
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern int lbl_805A03A8;
struct Flags { u8 rest : 7; u8 low : 1; };
extern "C" int fn_800D7A7C(u8* self, u8* out, int* out2) {
    u8 i = fn_800C8548();
    u8* p;
    if (i == 0xff) {
        p = 0;
    } else {
        p = (u8*)((u32)self + i * 0x218 + 0x70);
    }
    if (!p) return 1;
    u8 j = fn_800C851C();
    if (j == 0xff) j = 4;
    u8* q =self + j * 0x218;
    u8 state = q[0xd2];
    if (state == 0xff) return 0;
    u8 a = p[0x6c];
    u8 b = p[0x6d];
    unsigned int old;
    u8 c = p[0x6e];
    if (a == 0xff || (old = self[0xfcd], old != a) || self[0xfce] != b) {
        if (*(int*)(q + 0xcc)) {
            *(int*)(q + 0xcc) = 0;
            q[0xd0] = 0xff;
            q[0xd1] = 0;
            q[0xd2] = 0;
            j = fn_800C851C();
            if (j == 0xff) j = 4;
            u8* q2 = self + j * 0x218;
            ((Flags*)(q2 + 0xc6))->low = 0;
            fn_800D0AE0(self, q2);
            fn_80145B98(lbl_805A03A8, 0xfe);
        }
        *out = self[0xfcd];
        *out2 = self[0xfce];
        self[0xfcd] = a;
        self[0xfce] = b;
        return 1;
    }
    if (q[0xd0] == a && q[0xd1] == b && state == c) return 0;
    *out = old;
    *out2 = self[0xfce];
    self[0xfcd] = a;
    self[0xfce] = b;
    return 1;
}