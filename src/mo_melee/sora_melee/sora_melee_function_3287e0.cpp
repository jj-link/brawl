#pragma force_active on
#include <mt/mt_vector.h>

#define DV(n) virtual void f##n();

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void fn_27_328378(void* obj, Vec3f* a, Vec2f* b, int c, float d);
extern "C" int checkDeadArea__12soGroundUtilFP5Vec3fff(Vec3f* pos, float a, float b);
extern "C" extern const char lbl_27_data_86C00[];
extern "C" extern const char lbl_27_data_248[];
extern "C" extern const char lbl_27_data_2D0F0[];
extern "C" extern const float lbl_27_rodata_75C0;

class Dyn {
public:
    virtual void base0();
};

struct Pad4 {
    int a;
};

struct PadY {
    char pad[0x38];
};

class R29 : public Pad4, public Dyn {
public:
    DV(3) DV(4) DV(5) DV(6) DV(7) DV(8) DV(9) DV(10) DV(11) DV(12) DV(13) DV(14) DV(15) DV(16) DV(17) DV(18) DV(19) DV(20) DV(21) DV(22) DV(23) DV(24) DV(25) DV(26) DV(27) DV(28) DV(29) DV(30) DV(31) DV(32) DV(33) DV(34)
    virtual Vec3f f35(int);
    DV(36) DV(37) DV(38) DV(39) DV(40) DV(41) DV(42) DV(43) DV(44) DV(45) DV(46) DV(47) DV(48) DV(49) DV(50) DV(51) DV(52) DV(53) DV(54)
    virtual int f55(int, int);
    DV(56)
    virtual Vec2f f57(int, int);
    DV(58) DV(59) DV(60) DV(61) DV(62) DV(63) DV(64) DV(65) DV(66) DV(67) DV(68) DV(69) DV(70) DV(71) DV(72) DV(73) DV(74) DV(75) DV(76) DV(77) DV(78) DV(79) DV(80) DV(81) DV(82) DV(83) DV(84) DV(85)
    virtual Vec2f f86(int);
    DV(87) DV(88) DV(89) DV(90) DV(91) DV(92) DV(93) DV(94) DV(95) DV(96) DV(97) DV(98) DV(99) DV(100) DV(101) DV(102) DV(103) DV(104) DV(105) DV(106) DV(107) DV(108) DV(109) DV(110)
    virtual float f111(float);
};

inline void getVec(R29* r, Vec2f& out) { out = r->f57(0xff, 0); }

class Y : public PadY, public Dyn {
public:
    DV(3) DV(4) DV(5) DV(6) DV(7) DV(8) DV(9) DV(10) DV(11) DV(12) DV(13) DV(14) DV(15) DV(16) DV(17) DV(18) DV(19) DV(20) DV(21) DV(22) DV(23) DV(24) DV(25) DV(26) DV(27) DV(28) DV(29) DV(30) DV(31) DV(32) DV(33) DV(34) DV(35) DV(36) DV(37) DV(38) DV(39) DV(40) DV(41) DV(42)
    virtual void f43();
    DV(44) DV(45) DV(46) DV(47) DV(48) DV(49) DV(50) DV(51) DV(52) DV(53) DV(54) DV(55) DV(56) DV(57) DV(58) DV(59) DV(60) DV(61) DV(62) DV(63) DV(64) DV(65) DV(66) DV(67) DV(68) DV(69) DV(70) DV(71) DV(72) DV(73) DV(74) DV(75) DV(76) DV(77) DV(78) DV(79) DV(80) DV(81) DV(82) DV(83) DV(84) DV(85) DV(86) DV(87) DV(88) DV(89) DV(90) DV(91) DV(92) DV(93) DV(94) DV(95) DV(96) DV(97) DV(98) DV(99) DV(100) DV(101) DV(102) DV(103) DV(104) DV(105) DV(106) DV(107) DV(108) DV(109) DV(110) DV(111) DV(112) DV(113) DV(114) DV(115) DV(116) DV(117) DV(118) DV(119) DV(120) DV(121) DV(122) DV(123) DV(124) DV(125) DV(126) DV(127) DV(128) DV(129) DV(130) DV(131) DV(132) DV(133) DV(134) DV(135) DV(136) DV(137)
    virtual void f138(int);
};

class SoNull {
public:
    virtual void isNull();
    DV(1) DV(2) DV(3) DV(4) DV(5) DV(6) DV(7) DV(8) DV(9) DV(10) DV(11) DV(12) DV(13) DV(14) DV(15) DV(16)
    virtual int f17(unsigned int);
    DV(18) DV(19)
    virtual void f20(int, unsigned int);
};

struct X;

struct Arg {
    char pad0[8];
    void* p8;
    char pad1[0xcc];
    X* pD8;
};

struct X {
    char pad0[0x10];
    R29* m10;
    char pad1[0x50];
    SoNull* m64;
};

extern "C" void fn_27_3287E0(void*, Arg* arg) {
    SoNull* m;
    R29* r;
    R29* r2;
    R29* r3;
    Y* y;
    Vec3f a;
    Vec2f b;
    y = (Y*)__dynamic_cast(arg->p8, 0x3c, lbl_27_data_86C00, lbl_27_data_248, 1);
    m = arg->pD8->m64;
    if (!m->f17(0x12000003)) goto fail;
    r = arg->pD8->m10;
    {
        int r31 = r->f55(0xff, 0);
        if (r31) {
            a = r->f35(0);
            getVec(r, b);
        }
        if (!r31) goto fail;
    }
    fn_27_328378(y, &a, &b, 1, lbl_27_rodata_75C0);
    r2 = 0;
    y->f43();
    goto done;
fail:
    r2 = (R29*)1;
done:
    m->f20((int)r2, 0x12000003);
    r3 = arg->pD8->m10;
    Vec2f c = r3->f86(0);
    float z = r3->f111(c.m_x);
    Vec3f pos(c.m_x, c.m_y, z);
    if (checkDeadArea__12soGroundUtilFP5Vec3fff(&pos, lbl_27_rodata_75C0, lbl_27_rodata_75C0) != -1) {
        ((Y*)__dynamic_cast(arg->p8, 0x3c, lbl_27_data_2D0F0, lbl_27_data_248, 1))->f138(0);
    }
}
