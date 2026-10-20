#include <types.h>
#pragma force_active on

struct Sub {
    virtual u32 vf0();
    virtual u32 vf1();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual u32 vf5();
    virtual u32 vf6();
};

struct Outer {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Sub sub;
};

extern "C" u32 fn_27_D7E78(Outer* self) {
    return self->sub.vf4();
}
