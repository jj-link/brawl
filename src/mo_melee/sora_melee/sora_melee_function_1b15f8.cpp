#include <types.h>
#pragma force_active on

class A {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

extern "C" {
void fn_27_1B15F8(A* p) {
    A* q = (A*)((char*)p + 0x10);
    q->f3();
}
}
