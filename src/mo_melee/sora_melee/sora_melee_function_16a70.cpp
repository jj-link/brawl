#include <types.h>
#pragma force_active on

struct fn27Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f12(void* a, void* b);
};

extern "C" void fn_27_16A70(void* self, void* arg) {
    short buf = 2;
    fn27Obj* obj = *(fn27Obj**)((u8*)self + 0x168);
    obj = *(fn27Obj**)((u8*)obj + 0xd8);
    obj = *(fn27Obj**)((u8*)obj + 0x6c);
    obj->f12(&buf, arg);
}
