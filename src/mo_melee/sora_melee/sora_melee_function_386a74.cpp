#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <types.h>
#pragma force_active on
#define DUM(n) virtual void d##n();
extern "C" float lbl_27_rodata_7C50;
extern "C" float lbl_27_rodata_7C54;
class Work {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5)
    DUM(6) DUM(7) DUM(8) DUM(9) DUM(10) DUM(11)
    virtual float getFloat(u32);
    DUM(13)
};
class Kinetic {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5)
    DUM(6) DUM(7) DUM(8) DUM(9) DUM(10) DUM(11) DUM(12)
    virtual Vec2f slot13(s16*);
};
class Link {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5)
    DUM(6) DUM(7) DUM(8) DUM(9) DUM(10)
    virtual int slot11(int);
};
class Status {
public:
    DUM(0) DUM(1) DUM(2)
    virtual void slot3(u32, soModuleAccesser*);
};
struct GroundPrefix { char padding[8]; };
class GroundIface : public GroundPrefix {
public:
    DUM(0) DUM(1) DUM(2) DUM(3) DUM(4) DUM(5) DUM(6) DUM(7) DUM(8) DUM(9)
    DUM(10) DUM(11) DUM(12) DUM(13) DUM(14) DUM(15) DUM(16) DUM(17) DUM(18) DUM(19)
    DUM(20) DUM(21) DUM(22) DUM(23) DUM(24) DUM(25) DUM(26) DUM(27) DUM(28) DUM(29)
    DUM(30) DUM(31) DUM(32) DUM(33) DUM(34) DUM(35) DUM(36) DUM(37) DUM(38) DUM(39)
    DUM(40) DUM(41) DUM(42) DUM(43) DUM(44) DUM(45) DUM(46) DUM(47) DUM(48) DUM(49)
    DUM(50) DUM(51)
    virtual u32 slot52(int, float, float);
};
extern "C" Kinetic* fn_27_8CE14(void*);
extern "C" void fn_27_386A74(void*, soModuleAccesser* self) {
    float f31 = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x11000019);
    float f28 = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x1100001B);
    float f30 = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x16 + 0x11000000);
    float f29 = reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x1100001E);
    float a28 = (float)(double)nw4r::math::FAbs(f28);
    u32 r29 = 0;
    if (a28 < soValueAccesser::getConstantFloat(self, 0xFA5, 0)) {
        r29 = 1;
    }
    if (f30 * f31 < lbl_27_rodata_7C50) {
        r29 = 1;
    }
    if (r29 == 1) {
        float b28 = (float)(double)nw4r::math::FAbs(f28);
        if (b28 < reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x11000020)) {
            Link* lk = reinterpret_cast<Link*>(self->m_enumerationStart->m_linkModule);
            int v = lk->slot11(6);
            if (v != 0) {
                union { s16 value; int alignment; } spC;
                spC.value = 1;
                Kinetic* k0 = fn_27_8CE14((void*)v);
                Vec2f v1;
                Vec2f::copy(v1, k0->slot13(&spC.value));
                if (v1.lengthSq() > lbl_27_rodata_7C54) {
                    s16 sp8 = 1;
                    Kinetic* kin = reinterpret_cast<Kinetic*>(self->m_enumerationStart->m_kineticModule);
                    Vec2f v2;
                    Vec2f::copy(v2, kin->slot13(&sp8));
                    if (v2.m_x * v1.m_x > lbl_27_rodata_7C50) {
                        r29 = 0;
                    }
                }
            }
        }
    }
    float a30 = (float)(double)nw4r::math::FAbs(f29);
    if (a30 < soValueAccesser::getConstantFloat(self, 0xFA5, 0)) {
        if (f31 == reinterpret_cast<Work*>(self->m_enumerationStart->m_workManageModule)->getFloat(0x1100001F)) {
            r29 = 1;
        }
    } else {
        float constant = soValueAccesser::getConstantFloat(self, 0xFA5, 0);
        GroundIface* g = reinterpret_cast<GroundIface*>(self->m_enumerationStart->m_groundModule);
        if (g->slot52(0, f31, constant) == 1) {
            r29 = 1;
        }
    }
    if (r29 == 1) {
        reinterpret_cast<Status*>(self->m_enumerationStart->m_statusModule)->slot3(0x120, self);
    }
}
