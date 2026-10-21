#include <types.h>
#pragma force_active on

class IFoo {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual s32 f4();
    virtual void f5(s32 index, s32 value);
};

extern "C" bool fn_27_A20C8(IFoo* self, s32 a, s32 b) {
    s32 n = self->f4();
    if (n > b) {
        self->f5(n - 1, a);
        return (n - 1) == b;
    }
    return false;
}
