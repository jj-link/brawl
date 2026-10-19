#include <types.h>
#pragma force_active on

struct fn_27_84C44_Base {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void target(u32 a, u32 b, u16* out, s32 flag);
};

extern "C" {
void fn_27_84C44(fn_27_84C44_Base* self, u32 a, u32 b) {
    u16 local = 0;
    self->target(a, b, &local, -1);
}
}
