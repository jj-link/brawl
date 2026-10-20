#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

extern "C" {
void fn_27_1B15D8(char* p) {
    Inner* q = (Inner*)(p + 0x10);
    q->f3();
}
}
