#include <types.h>
#pragma force_active on

struct SubObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct OuterObj {
    s32 pad[4];
    SubObj sub;
};

extern "C" void fn_27_1BF730(OuterObj* p) {
    p->sub.vf1();
}
