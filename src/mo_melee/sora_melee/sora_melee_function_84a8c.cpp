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
    virtual void v20(u32 a, u32 b, u16* c, s32 d) = 0;
};

extern "C" void fn_27_84A8C(fn27Base* obj, u32 a, u32 b) {
    u16 flag = 0;
    obj->v20(a, b, &flag, -1);
}
