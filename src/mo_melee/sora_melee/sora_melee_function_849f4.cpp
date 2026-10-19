#include <types.h>
#pragma force_active on

struct fn_27_VBase {
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20(s32 a, s32 b, u16* out, s32 c);
};

extern "C" void fn_27_849F4(fn_27_VBase* self, s32 a, s32 b) {
    u16 val = 0;
    self->vfn20(a, b, &val, -1);
}
