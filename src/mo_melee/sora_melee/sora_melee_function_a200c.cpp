#include <types.h>
#pragma force_active on

extern "C" int randi__Fl(long);

class fn_27_A200C_Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f7(s32, s32);
};

extern "C" {
void fn_27_A200C(fn_27_A200C_Iface* self, s32 min, s32 max, s32 arg) {
    if (max < min) {
        return;
    }
    max = (max == min) ? max : min + randi__Fl(max - min + 1);
    self->f7(max, arg);
}
}
