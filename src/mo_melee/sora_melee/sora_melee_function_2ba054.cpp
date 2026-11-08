#include <types.h>
#pragma force_active on

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(s32);
};

struct Outer {
    char pad0[0x38];
    s32 m38;
    char pad1[0x8c - 0x3c];
    Sub a8c;
    char pad2a;
    u8 f91;
    char pad2[0xd8 - 0x92];
    Sub ad8;
    char pad3a;
    u8 fdd;
    char pad3[0xf8 - 0xde];
    Sub af8;
    char pad4a;
    u8 ffd;
    char pad4[0x130 - 0xfe];
    Sub a130;
    char pad5a;
    u8 f135;
    char pad5[0x1b4 - 0x136];
    Sub a1b4;
    char pad6a;
    u8 f1b9;
    char pad6[0x200 - 0x1ba];
    Sub a200;
    char pad7a;
    u8 f205;
    char pad7[0x23c - 0x206];
    Sub a23c;
    char pad8a;
    u8 f241;
    char pad8[0x250 - 0x242];
    Sub a250;
    char pad9a;
    u8 f255;
    char pad9[0x280 - 0x256];
    Sub a280;
    char pada;
    u8 f285;
};

extern "C" void fn_27_2BA054(Outer* self, s32 arg1, s16* arg2) {
    if (self->m38 != -1) {
        if (*arg2 & 4) {
            if ((self->f241 >> 7) & 1) {
                self->a23c.v8(arg1);
            }
            if ((self->f285 >> 7) & 1) {
                self->a280.v8(arg1);
            }
        }
        if ((*arg2 & 8) && ((self->f255 >> 7) & 1)) {
            self->a250.v8(arg1);
        }
        if (*arg2 & 1) {
            if ((self->f91 >> 7) & 1) {
                self->a8c.v8(arg1);
            }
            if ((self->fdd >> 7) & 1) {
                self->ad8.v8(arg1);
            }
            if ((self->ffd >> 7) & 1) {
                self->af8.v8(arg1);
            }
            if ((self->f135 >> 7) & 1) {
                self->a130.v8(arg1);
            }
            if ((self->f1b9 >> 7) & 1) {
                self->a1b4.v8(arg1);
            }
            if ((self->f205 >> 7) & 1) {
                self->a200.v8(arg1);
            }
        }
    }
}
