#include <types.h>
#pragma force_active on

class fn_27_Obj {
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
    virtual float v17() = 0;
};

extern "C" {
float fn_27_151010(void* self) {
    u8* p = (u8*)self;
    if (*(s32*)(p + 0x160) == 0) {
        fn_27_Obj* obj = *(fn_27_Obj**)(p + 0x14c);
        return obj->v17();
    }
    fn_27_Obj* obj = *(fn_27_Obj**)(p + 0x14c);
    return -obj->v17();
}
}
