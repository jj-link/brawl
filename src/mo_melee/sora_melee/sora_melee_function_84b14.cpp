#include <types.h>
#pragma force_active on

class soVirtBase {
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
    virtual void v20(s32 a, s32 b, u16* out, s32 c) = 0;
};

extern "C" void fn_27_84B14(soVirtBase* self, s32 a, s32 b) {
    u16 tmp = 0;
    self->v20(a, b, &tmp, -1);
}
