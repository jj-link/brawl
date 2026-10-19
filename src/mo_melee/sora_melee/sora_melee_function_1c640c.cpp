#include <types.h>
#pragma force_active on

class fn27Base {
public:
    virtual void f0();
    virtual fn27Base* f3(void* p);
};

extern "C" {
void fn_27_1C640C(fn27Base* self, fn27Base* other, void* p);
}

extern "C" void fn_27_1C640C(fn27Base* self, fn27Base* other, void* p) {
    self = self->f3(p);
    *(u32*)self = *(u32*)other;
}
