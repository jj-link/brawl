#include <types.h>
#pragma force_active on

class soFn27Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual s32 v9(u32* p, s32 x);
};

extern "C" {
s16 fn_27_90238(soFn27Obj* obj, u32 value) {
    u32 tmp = value;
    return obj->v9(&tmp, -1);
}
}
