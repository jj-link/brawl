#include <types.h>
#pragma force_active on

struct fnInner {
    virtual int vf0() = 0;
    virtual int vf1() = 0;
    virtual int vf2() = 0;
    virtual int vf3() = 0;
    virtual int vf4() = 0;
    virtual int vf5() = 0;
    virtual int vf6() = 0;
    virtual int vf7() = 0;
    virtual int vf8() = 0;
    virtual int vf9() = 0;
    virtual int vf10() = 0;
    virtual int vf11() = 0;
    virtual int vf12() = 0;
    virtual int vf13() = 0;
    virtual int vf14() = 0;
    virtual int vf15() = 0;
};

struct fnOuter {
    u8 pad[0xf0];
    fnInner* inner;
};

extern "C" {
int fn_27_1CADC(fnOuter* p) {
    return p->inner->vf13();
}
}
