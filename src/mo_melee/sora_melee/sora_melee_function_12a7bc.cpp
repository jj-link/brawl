#include <types.h>
#include <mt/mt_vector.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int);
    virtual void slot4();
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56(int, int, int, float, float);
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90(int);
    virtual void slot91();
    virtual void slot92(int);
};

struct Class_90D8_base {
    char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0();
    virtual int fn_27_7ABD8();
};

struct Modules {
    void* pad0;
    Class_90D8* c3;
    Object_vptr_0* c4;
    char pad0c[0x58];
    Object_vptr_0* c1;
    char pad68[0x3c];
    Object_vptr_0* c5;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct ObjectBase {
    char pad[0x3c];
    virtual void s0();
};

#define DECL_STAGE_SLOT(n) virtual void s##n();

class Object : public ObjectBase {
public:
    char pad40[0x20];
    Accesser* accesser;
    char pad64[0xa8];
    int unk10c;
    char pad110[0x30];
    short unk140;
    char pad142[2];
    int unk144;

    DECL_STAGE_SLOT(1) DECL_STAGE_SLOT(2) DECL_STAGE_SLOT(3)
    DECL_STAGE_SLOT(4) DECL_STAGE_SLOT(5) DECL_STAGE_SLOT(6)
    DECL_STAGE_SLOT(7) DECL_STAGE_SLOT(8) DECL_STAGE_SLOT(9)
    DECL_STAGE_SLOT(10) DECL_STAGE_SLOT(11) DECL_STAGE_SLOT(12)
    DECL_STAGE_SLOT(13) DECL_STAGE_SLOT(14) DECL_STAGE_SLOT(15)
    DECL_STAGE_SLOT(16) DECL_STAGE_SLOT(17) DECL_STAGE_SLOT(18)
    DECL_STAGE_SLOT(19) DECL_STAGE_SLOT(20) DECL_STAGE_SLOT(21)
    DECL_STAGE_SLOT(22) DECL_STAGE_SLOT(23) DECL_STAGE_SLOT(24)
    DECL_STAGE_SLOT(25) DECL_STAGE_SLOT(26) DECL_STAGE_SLOT(27)
    DECL_STAGE_SLOT(28) DECL_STAGE_SLOT(29) DECL_STAGE_SLOT(30)
    DECL_STAGE_SLOT(31) DECL_STAGE_SLOT(32) DECL_STAGE_SLOT(33)
    DECL_STAGE_SLOT(34) DECL_STAGE_SLOT(35) DECL_STAGE_SLOT(36)
    DECL_STAGE_SLOT(37) DECL_STAGE_SLOT(38) DECL_STAGE_SLOT(39)
    DECL_STAGE_SLOT(40) DECL_STAGE_SLOT(41) DECL_STAGE_SLOT(42)
    DECL_STAGE_SLOT(43) DECL_STAGE_SLOT(44) DECL_STAGE_SLOT(45)
    DECL_STAGE_SLOT(46) DECL_STAGE_SLOT(47) DECL_STAGE_SLOT(48)
    DECL_STAGE_SLOT(49) DECL_STAGE_SLOT(50) DECL_STAGE_SLOT(51)
    DECL_STAGE_SLOT(52) DECL_STAGE_SLOT(53) DECL_STAGE_SLOT(54)
    DECL_STAGE_SLOT(55) DECL_STAGE_SLOT(56) DECL_STAGE_SLOT(57)
    DECL_STAGE_SLOT(58) DECL_STAGE_SLOT(59) DECL_STAGE_SLOT(60)
    DECL_STAGE_SLOT(61) DECL_STAGE_SLOT(62) DECL_STAGE_SLOT(63)
    DECL_STAGE_SLOT(64) DECL_STAGE_SLOT(65) DECL_STAGE_SLOT(66)
    DECL_STAGE_SLOT(67) DECL_STAGE_SLOT(68) DECL_STAGE_SLOT(69)
    DECL_STAGE_SLOT(70) DECL_STAGE_SLOT(71) DECL_STAGE_SLOT(72)
    DECL_STAGE_SLOT(73) DECL_STAGE_SLOT(74) DECL_STAGE_SLOT(75)
    DECL_STAGE_SLOT(76) DECL_STAGE_SLOT(77) DECL_STAGE_SLOT(78)
    DECL_STAGE_SLOT(79) DECL_STAGE_SLOT(80) DECL_STAGE_SLOT(81)
    DECL_STAGE_SLOT(82) DECL_STAGE_SLOT(83) DECL_STAGE_SLOT(84)
    DECL_STAGE_SLOT(85) DECL_STAGE_SLOT(86) DECL_STAGE_SLOT(87)
    DECL_STAGE_SLOT(88) DECL_STAGE_SLOT(89) DECL_STAGE_SLOT(90)
    DECL_STAGE_SLOT(91) DECL_STAGE_SLOT(92) DECL_STAGE_SLOT(93)
    DECL_STAGE_SLOT(94) DECL_STAGE_SLOT(95) DECL_STAGE_SLOT(96)
    DECL_STAGE_SLOT(97) DECL_STAGE_SLOT(98) DECL_STAGE_SLOT(99)
    DECL_STAGE_SLOT(100) DECL_STAGE_SLOT(101) DECL_STAGE_SLOT(102)
    DECL_STAGE_SLOT(103) DECL_STAGE_SLOT(104) DECL_STAGE_SLOT(105)
    DECL_STAGE_SLOT(106) DECL_STAGE_SLOT(107) DECL_STAGE_SLOT(108)
    DECL_STAGE_SLOT(109) DECL_STAGE_SLOT(110) DECL_STAGE_SLOT(111)
    DECL_STAGE_SLOT(112) DECL_STAGE_SLOT(113) DECL_STAGE_SLOT(114)
    DECL_STAGE_SLOT(115) DECL_STAGE_SLOT(116) DECL_STAGE_SLOT(117)
    DECL_STAGE_SLOT(118) DECL_STAGE_SLOT(119) DECL_STAGE_SLOT(120)
    DECL_STAGE_SLOT(121) DECL_STAGE_SLOT(122) DECL_STAGE_SLOT(123)
    DECL_STAGE_SLOT(124) DECL_STAGE_SLOT(125) DECL_STAGE_SLOT(126)
    DECL_STAGE_SLOT(127) DECL_STAGE_SLOT(128) DECL_STAGE_SLOT(129)
    DECL_STAGE_SLOT(130) DECL_STAGE_SLOT(131) DECL_STAGE_SLOT(132)
    DECL_STAGE_SLOT(133) DECL_STAGE_SLOT(134) DECL_STAGE_SLOT(135)
    DECL_STAGE_SLOT(136) DECL_STAGE_SLOT(137) DECL_STAGE_SLOT(138)
    DECL_STAGE_SLOT(139) DECL_STAGE_SLOT(140) DECL_STAGE_SLOT(141)
    DECL_STAGE_SLOT(142) DECL_STAGE_SLOT(143) DECL_STAGE_SLOT(144)
    DECL_STAGE_SLOT(145) DECL_STAGE_SLOT(146) DECL_STAGE_SLOT(147)
    DECL_STAGE_SLOT(148) DECL_STAGE_SLOT(149) DECL_STAGE_SLOT(150)
    DECL_STAGE_SLOT(151) DECL_STAGE_SLOT(152) DECL_STAGE_SLOT(153)
    DECL_STAGE_SLOT(154) DECL_STAGE_SLOT(155) DECL_STAGE_SLOT(156)
    DECL_STAGE_SLOT(157) DECL_STAGE_SLOT(158) DECL_STAGE_SLOT(159)
    DECL_STAGE_SLOT(160) DECL_STAGE_SLOT(161) DECL_STAGE_SLOT(162)
    DECL_STAGE_SLOT(163) DECL_STAGE_SLOT(164) DECL_STAGE_SLOT(165)
    DECL_STAGE_SLOT(166) DECL_STAGE_SLOT(167) DECL_STAGE_SLOT(168)
    DECL_STAGE_SLOT(169) DECL_STAGE_SLOT(170) DECL_STAGE_SLOT(171)
    DECL_STAGE_SLOT(172) DECL_STAGE_SLOT(173) DECL_STAGE_SLOT(174)
    DECL_STAGE_SLOT(175) DECL_STAGE_SLOT(176) DECL_STAGE_SLOT(177)
    DECL_STAGE_SLOT(178) DECL_STAGE_SLOT(179) DECL_STAGE_SLOT(180)
    DECL_STAGE_SLOT(181) DECL_STAGE_SLOT(182) DECL_STAGE_SLOT(183)
    DECL_STAGE_SLOT(184)
    virtual void* s185();
};

#undef DECL_STAGE_SLOT

class FtObj {
public:
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
    virtual int f19();
};

extern "C" void activate__11StageObjectFffP5Vec3fb(
    Object*, Vec3f*, bool, float, float);
extern "C" int fn_27_111E30(void*);
extern "C" unsigned char fn_27_1119B8(void*);
extern "C" char* g_ftManager;
extern const float lbl_27_rodata_1048;
extern const float lbl_27_rodata_104C;

extern "C" void fn_27_12A7BC(Object* self) {
    int r;
    unsigned int r30;
    int r29;
    Vec3f pos;

    pos.m_x = lbl_27_rodata_1048;
    pos.m_y = lbl_27_rodata_1048;
    pos.m_z = lbl_27_rodata_1048;

    activate__11StageObjectFffP5Vec3fb(
        self, &pos, false, lbl_27_rodata_104C, lbl_27_rodata_1048);

    r = ((FtObj*)(g_ftManager + 0xb4))->f19();
    if (self->unk140 != (short)r) {
        self->unk140 = (short)r;
        if ((short)r > -1)
            self->unk144 = 0;
    }

    self->accesser->modules->c1->slot5(self->unk10c, 0x10000000);
    void* owner = self->s185();
    r30 = fn_27_111E30(owner);
    if (r30 == 1)
        self->accesser->modules->c4->slot90(1);

    if (self->accesser->modules->c3->fn_27_7ABD8() == 0)
        self->s153();

    self->accesser->modules->c4->slot92(0);
    self->accesser->modules->c4->slot92(0x20);
    self->accesser->modules->c4->slot92(0x3f);
    self->accesser->modules->c4->slot92(0x32);
    self->accesser->modules->c4->slot92(0x31);
    self->s163();

    r29 = -1;
    void* owner2 = self->s185();
    if (fn_27_1119B8(owner2) == 0xc) {
        r29 = 0x1cc;
    } else if (r30 == 1) {
        r29 = 0x1cd;
        self->accesser->modules->c5->slot3(0);
    }

    if (r29 != -1)
        self->accesser->modules->c4->slot56(
            0, r29, 1, lbl_27_rodata_1048, lbl_27_rodata_104C);
}
