#include <types.h>
#pragma force_active on

class fn27Sub {
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
    virtual u32 v12(u32 arg) = 0;
};

extern "C" u32 fn_27_28EA08(char* self) {
    fn27Sub* sub = (fn27Sub*)(self + 0x2aac);
    return sub->v12(0x1100000d);
}
