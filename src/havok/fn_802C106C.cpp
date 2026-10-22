#include <types.h>
#pragma force_active on

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32 arg, f32 a, f32 b);
};

struct Item {
    s32 pad;
    Obj* obj;
};

struct Holder {
    s32 pad[3];
    Item* items;
    s32 count;
};

extern "C" void fn_802C106C(Holder* holder, s32 arg1, f32 farg0, f32 farg1) {
    for (s32 i = 0; i < holder->count; i++) {
        holder->items[i].obj->v9(arg1, farg0, farg1);
    }
}
