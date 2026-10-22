#include <types.h>
#pragma force_active on

extern "C" {
int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
}

struct Fn48Obj {
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

extern "C" void fn_800DB248(Fn48Obj* self) {
    if (self->m5C == 0) {
        int r5;
        if (self->m48 == 0) {
            r5 = 0x46;
        } else {
            r5 = 0x31;
        }
        self->m5C = fn_800BEEB8(0, self->m4C, r5, self->m40, self->m44, self->m58, 0, 0x2A, 0x2B, 0, 0, 0xF0);
    }
}
