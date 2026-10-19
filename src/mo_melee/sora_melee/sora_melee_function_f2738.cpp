#include <types.h>
#pragma force_active on

class fn27F2738Base {
public:
    virtual void f0();
    virtual fn27F2738Base* f1(u32 arg);
};

extern "C" void fn_27_F2738(fn27F2738Base* self, fn27F2738Base* src, u32 arg) {
    fn27F2738Base* p = self->f1(arg);
    *(u32*)p = *(u32*)src;
}
