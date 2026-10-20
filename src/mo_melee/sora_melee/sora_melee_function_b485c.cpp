#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf13(u32 p);
};

extern "C" {
void fn_27_B485C(soVirtBase* p) {
    p->vf13(0);
}
}
