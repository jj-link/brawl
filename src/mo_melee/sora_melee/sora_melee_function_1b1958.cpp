#include <types.h>
#pragma force_active on

class fn27Base {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual s32 target(u32 a, u32 b, u16* out, s32 flag) = 0;
};

extern "C" s32 fn_27_1B1958(fn27Base* self, u32 a, u32 b) {
    u16 local = 0;
    return self->target(a, b, &local, -1);
}
