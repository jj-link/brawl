#include <types.h>
#pragma force_active on

struct Primary {
    int x;
};

struct Obj : Primary {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void call(void*, void*, void*, u8);
};

extern "C" void* getEntity__14ftEntryManagerFUl(u32);
extern "C" Obj* fn_27_1240B8(void*);

extern "C" void fn_27_10D968(void* self, void* a2, void* a3, void* a4, u32 a5, void* a6) {
    u8 flag = 0;
    if (a5 == 1) flag |= 1;
    u32 entryId = *(u32*)((char*)self + 0x154);
    void* entry = getEntity__14ftEntryManagerFUl(entryId);
    void* input = *(void**)((char*)entry + 0x2c);
    Obj* obj = fn_27_1240B8(input);
    obj->call(a6, a3, a4, flag);
}
