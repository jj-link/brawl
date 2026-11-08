#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

class Obj {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15();
    virtual float s16();
};
struct Holder { char pad[0x5C]; Obj* o; };
struct Acc { char pad[0xD8]; Holder* h; };

extern "C" void fn_27_163738(void*, void*, void*, soModuleAccesser* accesser) {
    Vec3f a;
    a.m_x = lbl_27_rodata_1FC0;
    a.m_y = lbl_27_rodata_1FC0;
    a.m_z = lbl_27_rodata_1FC0;
    float f = ((Acc*)accesser)->h->o->s16();
    float c = soValueAccesser::getConstantFloat(accesser, 0xC0C, 0);
    Vec2f m;
    m.m_x = c * f;
    m.m_y = lbl_27_rodata_1FC0;
    fn_27_89D08(3, accesser, 6, &m, &a);
    Vec3f b;
    b.m_x = lbl_27_rodata_1FC0;
    b.m_y = lbl_27_rodata_1FC0;
    b.m_z = lbl_27_rodata_1FC0;
    Vec2f n;
    n.m_x = lbl_27_rodata_1FC0;
    n.m_y = lbl_27_rodata_1FC0;
    fn_27_89D08(1, accesser, 0, &n, &b);
}
