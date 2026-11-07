#include <so/so_value_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on

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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int id);
    virtual void slot13(unsigned int id, float value);
};

struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Owner { char pad[0xd8]; Modules* modules; };

extern float lbl_27_rodata_7C44;

static inline float clamp(float v, float lo, float hi) {
    float t = nw4r::math::FSelect(v - lo, v, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_27_3867BC(void*, Owner* owner) {
    float a = owner->modules->work->slot12(0x11000018);
    float y = owner->modules->work->slot12(0x21000005);
    a += owner->modules->work->slot12(0x21000004);
    float r;
    if ((float)fabs(y - a) < lbl_27_rodata_7C44) {
        r = y;
    } else {
        float c = soValueAccesser::getConstantFloat((soModuleAccesser*)owner, 0xfa3, 0);
        r = clamp(a, -c, c);
    }
    owner->modules->work->slot13(0x11000018, r);
}
