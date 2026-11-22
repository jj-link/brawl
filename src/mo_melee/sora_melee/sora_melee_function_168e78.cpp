#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float slot16();
};
class Status {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};
struct Modules {
    char pad0[0xc];
    Object_vptr_0* first;
    char pad10[0x4c];
    Object_vptr_0* second;
    char pad60[0x10];
    Status* status;
};
struct Access {
    char pad0[0xd8];
    Modules* modules;
};
extern "C" {
extern float lbl_27_rodata_20C0[];
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*, u32, u32);
float fn_27_168E78(Access* access) {
    Modules* modules = access->modules;
    Object_vptr_0* second = modules->second;
    float value = modules->first->slot9();
    float multiplier = second->slot16();
    value = multiplier * value;
    float low = 0.0f;
    float high = low;
    switch (access->modules->status->slot16()) {
    case 19:
        low = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xc3e, 0);
        high = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xc3f, 0);
        if (value < low) return 0.5f;
        if (value > high) return 1.0f;
        break;
    case 20:
        low = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xc40, 0);
        high = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xc41, 0);
        if (value > low) return 0.5f;
        if (value < high) return 1.0f;
        break;
    }
    float diff = high - low;
    if ((float)(double)nw4r::math::FAbs(diff) > 1.1920928955078125e-7f)
        return 0.5f + 0.5f * ((value - low) / diff);
    return 1.0f;
}
}