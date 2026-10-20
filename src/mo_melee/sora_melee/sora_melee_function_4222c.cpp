#pragma force_active on
#include <types.h>

class VirtObj {
public:
    virtual void f0();
    virtual s32 f1(s32);
};

struct P1Struct {
    u32 m0;
    s16 m4;
    s16 m6;
    u8 pad[0x2B];
    u8 m33;
};

extern "C" void fn_27_4222C(P1Struct* p1, VirtObj* p2, s32 p3) {
    s32 i = 0;
    while (i < p1->m6) {
        s32 ptr = p2->f1(p1->m4 + i);
        *(s32*)ptr = p3;
        i++;
    }
    p1->m33 = 1;
}
