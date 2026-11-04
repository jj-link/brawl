#include <types.h>
#pragma force_active on

extern "C" const float lbl_119_rodata_68;

class Virt {
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
    virtual float vf9();
};

struct PadC {
    char pad[0xc];
    Virt* unkC;
};

struct PadD8 {
    char pad[0xd8];
    PadC* unkD8;
};

extern "C" float fn_119_FAA4(float* arg0, float* arg1, PadD8* self) {
    float diff = *arg0 - *arg1;
    if (lbl_119_rodata_68 == diff) {
        return self->unkD8->unkC->vf9();
    }
    s32 sign;
    if (diff < lbl_119_rodata_68) {
        sign = -1;
    } else {
        sign = 1;
    }
    return (float)sign;
}
