#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(s32 value);
};

struct fnOuter {
    u32 unk0;
    u32 unk4;
    fnInner* unk8;
};

extern "C" void fn_27_DA5A4(fnOuter* self, s16 value) {
    self->unk8->v8(value);
}
