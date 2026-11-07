#include <wn/weapon.h>
#pragma force_active on
struct Param {
    unsigned task, a, b, c;
    int owner, team, f18, f1c;
    Vec3f pos;
    float lr;
    int value, f34, situation, status, f40, motion, f48;
    union {
        struct { u8 active : 1; u8 bits1 : 3; u8 bit4 : 1; u8 bits5 : 3; u8 bits6 : 2; u8 reserved : 6; } b;
        struct { u8 upper : 4; u8 lower : 4; } n;
    } flags;
    Param(unsigned t, unsigned r, int v, const Vec3f& p, float f)
        : task(t), a(r), b(r), c(r), owner(-1), team(-1), f18(0), f1c(0),
          pos(p), lr(f), value(v), f34(0), situation(2), status(0x80),
          f40(0), motion(0x35f), f48(0) {
        flags.b.active = 1; flags.b.bits1 = 0; flags.b.bit4 = 1; flags.b.bits6 = 0; flags.n.lower = 0;
    }
};
struct Motion {
virtual void f0();
virtual void f1();
virtual void f2();
virtual void f3();
virtual void f4();
virtual void f5();
virtual void f6();
virtual void f7();
virtual void f8();
virtual void f9();
virtual void f10();
virtual void f11();
virtual void f12();
virtual void f13();
virtual void f14();
virtual void f15();
virtual void f16();
virtual void f17();
virtual void f18();
virtual void f19();
virtual void f20();
virtual void f21();
virtual void f22();
virtual void f23();
virtual void f24();
virtual void f25();
virtual void f26();
virtual void f27();
virtual void f28();
virtual void f29();
virtual void f30();
virtual void f31();
virtual void f32();
virtual void f33();
virtual void f34();
virtual void f35();
virtual void f36();
virtual void f37();
virtual void f38();
virtual void f39();
virtual void f40();
virtual void f41();
virtual void f42();
virtual void f43();
virtual void f44();
virtual void f45();
virtual void f46();
virtual void f47();
virtual void f48();
virtual void f49();
virtual void f50();
virtual void f51();
virtual void f52();
virtual void f53();
virtual void f54();
virtual void f55();
virtual void add(int, unsigned, bool, float, float);
};
extern "C" {
extern const float lbl_113_rodata_150, lbl_113_rodata_148;
void fn_27_1D8370(void*, const Param*);
void fn_113_2952C(Weapon* object, unsigned task, unsigned resource, int value, const Vec3f* pos) {
    Param p(task, resource, value, *pos, lbl_113_rodata_150);
    fn_27_1D8370(object, &p);
    object->m_moduleAccesser->getWorkManageModule().onFlag(0x12000000);
    object->m_moduleAccesser->getMotionModule().removeOtherAnim(1);
    ((Motion*)&object->m_moduleAccesser->getMotionModule())->add(1, 7, false, lbl_113_rodata_150, lbl_113_rodata_148);
    object->m_moduleAccesser->getLinkModule().setAttribute(3, (soLinkConnection::Attribute)4, true);
    object->m_moduleAccesser->getLinkModule().setAttribute(3, (soLinkConnection::Attribute)2, true);
}
}