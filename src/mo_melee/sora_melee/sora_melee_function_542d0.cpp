#include <types.h>
#pragma force_active on

class fn27Base {
public:
    virtual void vf0();
    virtual void vf1();
};

extern "C" {
void fn_27_542D0(fn27Base* self) {
    self->vf1();
}
}
