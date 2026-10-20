#include <types.h>
#pragma force_active on

namespace {
struct T {
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void callA(s32, void*, s32);
    virtual void f17();
    virtual void callB(void*);
};
struct Local {
    u32 a;
    u8 b;
};
}

extern "C" void fn_27_382AF8(void* self) {
    Local local;
    local.a = 0x838;
    local.b = 0;
    
    void* p2 = *(void**)((u8*)*(void**)((u8*)self + 0x60) + 0xd8);
    T* obj1 = (T*)*(void**)((u8*)p2 + 0x54);
    obj1->callA(-1, &local, 0);
    
    void* p2b = *(void**)((u8*)*(void**)((u8*)self + 0x60) + 0xd8);
    T* obj2 = (T*)*(void**)((u8*)p2b + 0x64);
    obj2->callB((void*)0x1200003d);
}
