#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual s32 vf0();
    virtual s32 vf1();
    virtual s32 vf2();
    virtual s32 vf3();
    virtual s32 vf4();
    virtual s32 vf5();
    virtual s32 vf6();
    virtual s32 vf7();
    virtual s32 vf8();
    virtual s32 vf9();
    virtual s32 vf10();
    virtual s32 vf11();
    virtual s32 vf12();
    virtual s32 vf13();
    virtual s32 vf14();
    virtual s32 vf15();
    virtual s32 vf16();
    virtual s32 vf17();
    virtual s32 vf18();
    virtual s32 vf19();
    virtual s32 vf20();
    virtual s32 vf21();
};

struct fnOuter {
    u32 unk0;
    u32 unk4;
    fnInner* inner;
};

extern "C" {
s32 fn_27_DA704(fnOuter* p) {
    return p->inner->vf19();
}
}
