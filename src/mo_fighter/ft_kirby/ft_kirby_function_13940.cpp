#pragma force_active on

struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };
struct Accesser;

class Energy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void reset(int, Vec2f*, Vec3f*, Accesser*);
};

class Kinetic {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Energy* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void change(int, Accesser*);
};

struct Modules {
    char pad[0x7c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad0[8];
    void* object;
    char pad1[0xcc];
    Modules* modules;
};

struct FighterBase {
    char pad[0x3c];
};

#define V(n) virtual void v##n();

class Fighter : public FighterBase {
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
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138) V(139)
    V(140) V(141) V(142) V(143) V(144) V(145) V(146) V(147) V(148) V(149)
    V(150) V(151) V(152) V(153) V(154) V(155) V(156) V(157) V(158) V(159)
    V(160) V(161) V(162) V(163) V(164) V(165) V(166) V(167) V(168) V(169)
    V(170) V(171) V(172) V(173) V(174) V(175) V(176) V(177) V(178) V(179)
    V(180) V(181) V(182) V(183) V(184) V(185)
    virtual int kind();
};

#undef V

struct Params {
    char pad[0x74];
    float value;
    float pad2;
    float value2;
};

struct Info {
    char pad[8];
    float* values;
};

extern "C" {
extern const char lbl_96_data_608[];
extern const char lbl_96_data_68D8[];
extern const char lbl_96_data_B050[];
extern const char lbl_96_data_5E00[];
extern const float lbl_96_rodata_28;
extern const float lbl_96_rodata_2C;
extern char g_ftCommonDataAccesser;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Info* fn_96_AF98(void*);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
Params* getParam__20ftCommonDataAccesserCF6ftKind(const void*, int);
void fn_27_15CF5C(Energy*, float);
void fn_96_138F8(Energy*, const Vec2f*);

void fn_96_13940(void*, Accesser* a) {
    fn_96_AF98(__dynamic_cast(
        a->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1));

    Kinetic* k = a->modules->kinetic;
    k->change(0x13, a);

    Energy* e = (Energy*)__dynamic_cast(
        k->getEnergy(2), 0, lbl_96_data_B050, lbl_96_data_5E00, 1);

    Fighter* f = (Fighter*)__dynamic_cast(
        a->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1);

    Params* p = getParam__20ftCommonDataAccesserCF6ftKind(
        &g_ftCommonDataAccesser, f->kind());
    Info* info = fn_96_AF98(f);

    ((unsigned char*)e)[5] |= 0x80;

    Vec2f speed = {lbl_96_rodata_28, lbl_96_rodata_28};
    Vec3f rot;
    e->reset(4, &speed,
        fn_96_BC54(&rot, lbl_96_rodata_28,
                   lbl_96_rodata_28, lbl_96_rodata_28),
        a);

    fn_27_15CF5C(e, p->value * info->values[1]);

    Vec2f v = {p->value2, lbl_96_rodata_2C};
    fn_96_138F8(e, &v);
}
}
