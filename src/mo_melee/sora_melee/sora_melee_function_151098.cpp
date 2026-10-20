#include <types.h>
#pragma force_active on

class fnInner {
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
    virtual void vf11();
    virtual void vf12();
};

class fnOuter {
public:
    u32 pad[12];
    fnInner inner;
};

extern "C" {
void fn_27_151098(fnOuter* self) {
    fnInner* p = &self->inner;
    p->vf10();
}
}
