#include <types.h>
#pragma force_active on

class fnBase {
public:
    virtual void f0(s16 a, s8 b);
    virtual void f1();
};

extern "C" {
void fn_27_D3B38(fnBase* self, s16 a, s8 b) {
    self->f0(a, b);
}
}
