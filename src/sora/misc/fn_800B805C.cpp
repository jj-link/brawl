#include <types.h>
#pragma force_active on

class A {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};

extern "C" void fn_800B805C(int* self) {
    A* obj = *(A**)(self + 1);
    if (!obj)
        return;
    obj->m4();
}
