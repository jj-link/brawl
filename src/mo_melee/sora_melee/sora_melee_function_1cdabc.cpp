#include <types.h>
#pragma force_active on

class Base {
public:
    virtual void f0();
    virtual void* f1(void* p);
};

extern "C" {
void fn_27_1CDABC(Base* self, u32* src, void* arg) {
    u32* dst = (u32*)self->f1(arg);
    *dst = *src;
}
}
