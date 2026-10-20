#include <types.h>
#pragma force_active on

class DA194Obj {
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
    virtual s32 v20(u32*, s32, s16*, s32) = 0;
};

extern "C" {
s16 fn_27_DA194(u8* self, u32 p2, s8 p3) {
    s16 out = 0;
    DA194Obj* obj = *(DA194Obj**)(self + 8);
    return (s16)obj->v20(&p2, -1, &out, (s32)p3);
}
}
