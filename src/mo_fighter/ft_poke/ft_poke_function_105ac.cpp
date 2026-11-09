#include <wn/weapon.h>
#pragma force_active on
struct Param {
    unsigned task, a, b, c;
    int owner, team, f18, f1c;
    Vec3f pos;
    float lr;
    int value, f34, situation, status, f40, motion, f48;
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 bits2 : 2;
    u8 bit4 : 1;
    u8 bits5 : 3;
    u8 bits6 : 2;
    u8 reserved : 6;
    Param(unsigned t, unsigned r, int v, const Vec3f& p, float f)
        : task(t), a(r), b(r), c(r), owner(-1), team(-1), f18(0), f1c(0),
          pos(p), lr(f), value(v), f34(0), situation(2), status(0x80),
          f40(0), motion(0x35f), f48(0), bit0(1), bit1(1), bits2(0),
          bit4(1), bits5(0), bits6(0) {}
};
extern "C" {
void fn_27_1D8370(void*, const Param*);
void fn_116_105AC(Weapon* object, unsigned task, unsigned resource,
                  int value, const Vec3f* pos, float lr, float value2) {
    Param p(task, resource, value, *pos, lr);
    fn_27_1D8370(object, &p);
    object->m_moduleAccesser->getWorkManageModule().offFlag(0x12000003);
    object->m_moduleAccesser->getWorkManageModule().offFlag(0x12000004);
    object->m_moduleAccesser->getWorkManageModule().setInt(value, 0x10000005);
    object->m_moduleAccesser->getWorkManageModule().setFloat(value2, 0x11000002);
    object->m_moduleAccesser->getWorkManageModule().onFlag(0x12000000);
    object->m_moduleAccesser->getStatusModule().changeStatusForce(0, object->m_moduleAccesser);
    object->updateNodeSRT();
}
}