#include <types.h>
#pragma force_active on
extern "C" u8 fn_8004EAD4(void*);
extern void* g_GameGlobal;
struct Obj {
    char pad0[0xA0]; int a0; char padA4[0x4C]; int f0; int f4; u8 f8 : 1; u8 rest : 7; char f9; u8 fa; char padFB[5]; int f100; int f104; int f108;
};
extern "C" int fn_8003304C(Obj* self, int a, int n, u8 b) {
    if (n >= 3) return 0;
    if (self->f0 != 0) return 0;
    u32 v = fn_8004EAD4(g_GameGlobal);
    if (!(v & (1U << n))) {
        self->f0 = 0;
        self->a0 = 3;
        return 1;
    }
    self->f0 = 4;
    self->f4 = 0;
    self->f8 = 0;
    self->f100 = 0;
    self->fa = b;
    self->f104 = n;
    self->f108 = a;
    self->a0 = 0;
    return 1;
}