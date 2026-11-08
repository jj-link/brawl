#pragma force_active on

#include <so/link/so_link_module_impl.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/work/so_work_manage_module_impl.h>
#include <nw4r/math/math_arithmetic.h>

extern "C" {
extern const unsigned char lbl_121_data_7C34[];
extern const unsigned char lbl_121_data_3CF0[];
extern const float lbl_121_rodata_A0;
extern const float lbl_121_rodata_B0;

void* __dynamic_cast(void*, long, const void*, const void*, short);
float rsqrtf__Ff(float);
Vec3f fn_121_10470(const Vec3f*, const Vec3f*);
}

#define VB(n) virtual void m##n();

class BaseA {
public:
    char pad[0x3c];

    VB(0) VB(1) VB(2) VB(3) VB(4) VB(5) VB(6) VB(7) VB(8) VB(9)
    VB(10) VB(11) VB(12) VB(13) VB(14) VB(15) VB(16) VB(17) VB(18) VB(19)
    VB(20) VB(21) VB(22) VB(23) VB(24) VB(25) VB(26) VB(27) VB(28) VB(29)
    VB(30) VB(31) VB(32) VB(33) VB(34) VB(35) VB(36) VB(37) VB(38) VB(39)
    VB(40) VB(41) VB(42) VB(43) VB(44) VB(45) VB(46) VB(47) VB(48) VB(49)
    VB(50) VB(51) VB(52) VB(53) VB(54) VB(55) VB(56) VB(57) VB(58) VB(59)
    VB(60) VB(61) VB(62) VB(63) VB(64) VB(65) VB(66) VB(67) VB(68) VB(69)
    VB(70) VB(71) VB(72) VB(73) VB(74) VB(75) VB(76) VB(77) VB(78) VB(79)
    VB(80) VB(81) VB(82) VB(83) VB(84) VB(85) VB(86) VB(87) VB(88) VB(89)
    VB(90) VB(91) VB(92) VB(93) VB(94) VB(95) VB(96) VB(97) VB(98) VB(99)
    VB(100) VB(101) VB(102) VB(103) VB(104) VB(105) VB(106) VB(107) VB(108) VB(109)
    VB(110) VB(111) VB(112) VB(113) VB(114) VB(115) VB(116) VB(117) VB(118) VB(119)
    VB(120) VB(121) VB(122) VB(123) VB(124) VB(125) VB(126) VB(127) VB(128) VB(129)
    VB(130) VB(131) VB(132) VB(133) VB(134) VB(135) VB(136) VB(137)
    virtual void m138(int);
};

struct Param {
    char pad[0x38];
    unsigned int node;
    float distance;
};

class Fighter : public BaseA {
public:
    char pad2[0x20e4 - 0x40];
    Param* param;
};

struct Event : soLinkEventArgs {
    Event() : soLinkEventArgs(0x838) {}
    bool done() { return _0x4; }
};

struct KinM {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int, void*);
};

struct Modules {
    char pad0[0xc];
    soPostureModule* posture;
    char pad1[0x44];
    soLinkModule* link;
    char pad2[0xc];
    soWorkManageModule* work;
    char pad3[8];
    KinM* kinetic;
};

struct Accesser {
    char pad0[8];
    void* object;
    char pad1[0xcc];
    Modules* modules;
};

inline Vec3f difference(const Vec3f& a, const Vec3f& b) {
    return fn_121_10470(&a, &b);
}

inline void callFighter(Fighter* fighter) {
    fighter->m138(0);
}

inline Param* getParameters(Accesser* self, Fighter*& fighter) {
    fighter = static_cast<Fighter*>(__dynamic_cast(
        self->object, 0x3c, lbl_121_data_7C34, lbl_121_data_3CF0, 1));
    return fighter->param;
}

extern "C" void fn_121_15120(void*, Accesser* self) {
    if (self->modules->link->isLink(1) != true)
        return;

    if (self->modules->work->isFlag(0x12000004) != false)
        return;

    Fighter* fighter;
    Param* param = getParameters(self, fighter);

    Vec3f a = self->modules->link->getParentModelNodeGlobalPosition(
        1, param->node, true);
    Vec3f c = difference(a, self->modules->posture->getPos());

    float s = c.m_z * c.m_z + (c.m_x * c.m_x + c.m_y * c.m_y);
    float r;
    if ((float)(double)nw4r::math::FAbs(s) <= lbl_121_rodata_B0)
        r = lbl_121_rodata_A0;
    else
        r = s * rsqrtf__Ff(s);

    if (r <= param->distance) {
        Event event;
        self->modules->link->sendEventParents(1, event);
        if (event.done() == true)
            self->modules->kinetic->s5(1, self);
        else
            callFighter(fighter);
    }
}
