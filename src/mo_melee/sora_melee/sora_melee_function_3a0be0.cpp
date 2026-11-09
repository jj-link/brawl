#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int value, u32 id);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float value, u32 id);
};

struct Inner {
    char pad[0x64];
    Object_vptr_0* module;
};

struct Outer {
    char pad[0xD8];
    Inner* inner;
};

extern "C" {
float fn_27_39F928(soModuleAccesser*);
extern const float lbl_27_rodata_7E40[];
}

extern "C" void fn_27_3A0BE0(soModuleAccesser* accesser) {
    const float* c = (const float*)((u32)lbl_27_rodata_7E40);
    Object_vptr_0* m = ((Outer*)accesser)->inner->module;

    m->slot5(soValueAccesser::getConstantInt(accesser, 0x5DC1, 0), 0x10000007);
    m->slot13(c[6], 0x11000005);
    m->slot13(soValueAccesser::getConstantFloat(accesser, 0xFA3, 0), 0x11000006);
    m->slot13(c[0], 0x11000007);

    float value = fn_27_39F928(accesser);
    float zero = c[0];
    float a = c[7] + c[7] * value;
    float b = c[8] + c[9] * zero;
    float start = soValueAccesser::getConstantFloat(accesser, 0xFA4, 0);
    float end = soValueAccesser::getConstantFloat(accesser, 0xFA5, 0);

    m->slot13((start + value * (end - start)) * (a * b), 0x11000008);
}
