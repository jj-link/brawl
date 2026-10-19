#include <types.h>
#pragma force_active on

struct Ret {
    u32 f0;
    s32 val;
};

struct Inner {
    virtual ~Inner();
    virtual Ret* getPtr();
};

struct Obj {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    Inner inner;
};

extern "C" s32 fn_27_AFF70(Obj* obj) {
    return obj->inner.getPtr()->val;
}
