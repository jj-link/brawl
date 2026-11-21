#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

class ControllerMod {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual float s16();
};

struct KineticFlags {
    char pad[5];
    s8 flags;
};

class KineticMod {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5();
    virtual KineticFlags* s6(int);
};

struct EnumLike {
    char pad[0x5C];
    ControllerMod* controller; // 0x5C
    char pad2[0x1C];
    KineticMod* kinetic; // 0x7C
};

struct AccesserLike {
    char pad[0xD8];
    EnumLike* enumStart; // 0xD8
};

static inline float getY(double y) {
    return y;
}

extern "C" void fn_27_161E50(int, int, int, soModuleAccesser* accesser) {
    AccesserLike* a = (AccesserLike*)accesser;
    Vec3f z2;
    Vec3f z1;
    Vec2f tmp;
    Vec2f v2;
    Vec2f v1;
    float first = soValueAccesser::getConstantFloat(accesser, 0xC27, 0);
    float second = soValueAccesser::getConstantFloat(accesser, 0xC28, 0) * a->enumStart->controller->s16();

    tmp.m_y = first;
    tmp.m_x = second;
    float y = getY(first);

    z1.m_x = lbl_27_rodata_1FC0;
    z1.m_y = lbl_27_rodata_1FC0;
    z1.m_z = lbl_27_rodata_1FC0;
    v1.m_x = lbl_27_rodata_1FC0;
    v1.m_y = y;
    ((void (*)(int, soModuleAccesser*, int, Vec2f*, Vec3f*, float))fn_27_89D08)(1, accesser, 0, &v1, &z1, second);

    float t = tmp.m_x;
    z2.m_x = lbl_27_rodata_1FC0;
    z2.m_y = lbl_27_rodata_1FC0;
    z2.m_z = lbl_27_rodata_1FC0;
    v2.m_x = t;
    v2.m_y = lbl_27_rodata_1FC0;
    fn_27_89D08(2, accesser, 0, &v2, &z2);

    a->enumStart->kinetic->s6(4)->flags &= ~0x80;
}
