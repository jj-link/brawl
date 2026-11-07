#include <types.h>
#pragma force_active on

extern "C" {
int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
}

struct Fn5CObj {
    u8 pad0[0x40];
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    int m58;
    int m5C;
};

extern "C" void fn_800DAD80(Fn5CObj* self) {
    if (self->m5C == 0) {
        self->m5C = fn_800BEEB8(1, self->m4C, 0x44, self->m40, self->m44, self->m58, 0, 0x2A, 0x2B, 0, 0, 0xF0);
    }
}
