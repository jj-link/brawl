#include <types.h>
#pragma force_active on

struct Fn27Args {
    s32 id;
    u8 flag;
};

class Fn27Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(s32, Fn27Args*, s32);
};

extern "C" {
void fn_27_383724(void* self) {
    Fn27Args args;
    void* a = *(void**)((u8*)self + 0x60);
    args.id = 0x83a;
    args.flag = 0;
    void* b = *(void**)((u8*)a + 0xd8);
    Fn27Obj* obj = (Fn27Obj*)*(void**)((u8*)b + 0x54);
    obj->v16(-1, &args, 0);
}
}
