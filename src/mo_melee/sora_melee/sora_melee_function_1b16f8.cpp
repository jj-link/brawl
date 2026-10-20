#include <types.h>
#pragma force_active on

struct IObj {
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
    virtual s32 request(u32*, s32, u16*, s8) = 0;
};

struct Holder {
    void* a;
    void* b;
    IObj* obj;
};

struct Locals {
    u32 id;
    u16 index;
};

extern "C" s16 fn_27_1B16F8(Holder* holder, u32 param1, s8 param2) {
    Locals l;
    l.index = 0;
    l.id = param1;
    return (s16)holder->obj->request(&l.id, -1, &l.index, param2);
}
