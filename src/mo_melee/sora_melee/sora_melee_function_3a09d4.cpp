#pragma force_active on
#pragma fp_contract off

#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>
#include <so/so_value_accesser.h>

struct Pair {
    float x, y;
};

struct Pad8 {
    char pad[8];
};

#define V(n) virtual void s##n();

class Controller : public Pad8 {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54)
    virtual int test(int, int);
    V(56)
    virtual unsigned long long get(int, int);
};

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
};

struct Pad60 {
    char pad[0x3c];
};

class Target : public Pad60 {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108) V(109)
    V(110) V(111) V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119)
    V(120) V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137)
    virtual void end(int);
};

#undef V

struct Modules {
    char pad[0xc];
    Object_vptr_0* posture;
    Controller* controller;
};

struct Access {
    char pad[8];
    void* object;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" {
extern char lbl_27_data_9B6C0[];
extern char lbl_27_data_248[];

void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_27_3A09D4(void*, Access* access) {
    Pair v;
    v.x = 0.0f;
    v.y = 0.0f;
    Controller* mod = access->modules->controller;

    if (mod->test(8, 0)) {
        unsigned long long bits = mod->get(8, 0);
        v = *(Pair*)&bits;
    } else if (mod->test(1, 0)) {
        unsigned long long bits = mod->get(1, 0);
        v = *(Pair*)&bits;
    }

    float sum = v.x * v.x + v.y * v.y;
    float len;
    if ((float)(double)nw4r::math::FAbs(sum) <= 1.17549435e-38f) {
        len = 0.0f;
    } else {
        len = sum * rsqrtf(sum);
    }

    if (len > 9.99999975e-6f) {
        double y = v.y;
        double x = v.x;
        float a = (float)(double)nw4r::math::FAbs((float)atan2(x, y));
        float c = soValueAccesser::getConstantFloat(
            (soModuleAccesser*)access, 0xfaf, 0);
        float t = 0.0174532924f * c;
        float upper = 3.14159274f - t;

        if (a > t && a < upper) {
            float d = access->modules->posture->slot9();
            if (v.x * d < -9.99999975e-6f) {
                Target* o = (Target*)__dynamic_cast(
                    access->object, 0x3c,
                    lbl_27_data_9B6C0, lbl_27_data_248, 1);
                o->end(0);
            }
        }
    }
}
}
