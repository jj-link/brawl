#include <types.h>
#pragma force_active on

struct Obj {
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8(s32);
};

struct Element {
    u8 pad[4];
    Obj* obj;
};

struct Holder {
    u8 pad[0xC];
    Element* elements;
    s32 count;
};

extern "C" void fn_802C0FE8(Holder* arg0, s32 arg1) {
    for (s32 i = 0; i < arg0->count; i++) {
        Obj* obj = arg0->elements[i].obj;
        obj->method8(arg1);
    }
}
