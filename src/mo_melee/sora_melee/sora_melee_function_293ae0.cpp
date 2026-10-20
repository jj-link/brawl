#include <types.h>
#pragma force_active on

class soSubObject {
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
};

class soOuterObject {
public:
    u32 unk0[4];
    soSubObject sub;
};

extern "C" {
void fn_27_293AE0(soOuterObject* self) {
    self->sub.vf8();
}
}
