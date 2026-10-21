#include <types.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_450;

struct Vec4 {
    float x, y, z, w;
};

class S {
public:
    virtual void v0();
    virtual void v1();
    virtual int isActive();

    unsigned char pad[4]; // 0x4
    int ints[3];          // 0x8
    float f[4];           // 0x14
    unsigned char b24;
    unsigned char b25;
};

extern "C" void fn_27_33E20(S* self) {
    if (self->isActive()) {
        Vec4 local;
        self->ints[0] = 0xFFFF;
        self->ints[1] = 0xFFFF;
        self->ints[2] = 0xFFFF;
        self->b24 = 0;
        local.x = lbl_27_rodata_450;
        local.y = lbl_27_rodata_450;
        self->f[0] = local.x;
        self->f[1] = local.y;
        local.z = lbl_27_rodata_450;
        local.w = lbl_27_rodata_450;
        self->f[2] = local.z;
        self->f[3] = local.w;
        self->b25 = 0;
    }
}
