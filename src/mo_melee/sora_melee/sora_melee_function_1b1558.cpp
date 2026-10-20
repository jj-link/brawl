#include <types.h>
#pragma force_active on

class D {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual bool m() = 0;
};

extern "C" bool fn_27_1B1558(void* self) {
    D* d = (D*)((char*)self + 0x10);
    return d->m();
}
