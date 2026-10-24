#include <types.h>
#pragma force_active on

extern "C" void fn_80041F70(void *, unsigned char *, int, float);
extern "C" float lbl_805A13A0;

struct Obj {
    unsigned char pad0[0x1C];
    unsigned char flags;
    unsigned char pad1[0x23];
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    unsigned char b43;
};

extern "C" void fn_80011170(Obj *arg0) {
    unsigned char sp8[4];

    if (!((arg0->flags >> 5) & 1)) {
        sp8[0] = arg0->b40;
        sp8[1] = arg0->b41;
        sp8[2] = arg0->b42;
        sp8[3] = arg0->b43;
        fn_80041F70((char *)arg0 + 0x2C, sp8, 0, lbl_805A13A0);
    }
}
