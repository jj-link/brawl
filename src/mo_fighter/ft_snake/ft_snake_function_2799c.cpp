#include <nw4r/math/math_arithmetic.h>
#include <types.h>

#pragma force_active on

extern "C" const float lbl_122_rodata_1AC;

class Class_7EA0 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_19BC();
    virtual void fn_122_F640();
    virtual void fn_122_F638();
    virtual int fn_122_F630(u32);
    virtual void fn_122_F628(u32, u32);
    virtual void fn_122_F620();
    virtual void fn_122_F618();
    virtual void fn_122_F610(u32);
};

class Class_Unk50 {
public:
    virtual void fn_122_ABB4();
    virtual void fn_122_19BC();
    virtual void fn_122_F640();
    virtual void fn_122_F638();
    virtual void fn_122_F630();
    virtual void fn_122_F628(u32, bool, bool, u32);
};

struct Modules {
    char pad0[0x50];
    Class_Unk50* unk50;
    char pad1[0x10];
    Class_7EA0* unk64;
};

struct Self {
    char pad0[0xD8];
    Modules* modules;
};

extern "C" void fn_122_2799C(float value, void*, Self* self) {
    if (self->modules->unk64->fn_122_F630(0x20000003) > 0) {
        self->modules->unk64->fn_122_F610(0x20000003);
        return;
    }
    if ((float)(double)nw4r::math::FAbs(value) <= lbl_122_rodata_1AC) {
        return;
    }
    self->modules->unk50->fn_122_F628(0x18EA, false, false, 0);
    self->modules->unk64->fn_122_F628(0xA, 0x20000003);
}
