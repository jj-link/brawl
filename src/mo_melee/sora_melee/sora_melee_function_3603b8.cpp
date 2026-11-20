#include <types.h>

#pragma force_active on

struct Obj64 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(unsigned int, float);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(unsigned int, void*);
};

struct Obj7C {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
};

struct Modules {
    char pad0[0x64];
    Obj64* p64;
    char pad68[0x14];
    Obj7C* p7C;
};

struct Self {
    char pad[0xD8];
    Modules* modules;
};

struct Vec2 {
    float x;
    float y;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
double sin(float);
double cos(float);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern const float lbl_27_rodata_7A40[];
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];

void fn_27_3603B8(void*, Self* self) {
    float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                      self, 0xFA6, 0) * self->modules->p64->slot12(0x21000000);

    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                  self, 0xFA5, 0);
    self->modules->p64->slot5((int)(c + scale), 0x20000000);

    float* result = (float*)__dynamic_cast(
        self->modules->p7C->slot6(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

    float magnitude;
    if (self->modules->p64->slot17(0x12000003, self->modules) == 1) {
        magnitude = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            self, 0xFA1, 0);
    } else {
        magnitude = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            self, 0xFA3, 0);
    }

    float angle = lbl_27_rodata_7A40[0] * self->modules->p64->slot12(0x11000002);
    float vertical = magnitude * (float)sin(angle);
    float cosine = (float)cos(angle);
    float horizontal = magnitude * cosine;

    {
        Vec2 v = { horizontal, vertical };
        *(Vec2*)(result + 2) = v;
    }

    self->modules->p64->slot13(0x11000001, magnitude);
}
}
