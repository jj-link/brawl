#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_112E48(void*);
extern char lbl_27_data_2E380[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern char lbl_27_data_69C0[];
extern char lbl_27_data_248[];
}

struct MotionRequest {
    int motion;
    float frame;
    float rate;
    unsigned char a, b, c, d;
};

struct CollisionParams {
    float a, b, c, d, e, f, g;
    unsigned int id : 9;
    unsigned int field9 : 2;
    unsigned int field11 : 2;
    unsigned int field13 : 2;
    unsigned int field15 : 1;
    unsigned int remaining : 16;
};

class Posture {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
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
    virtual float slot22();
    virtual void slot23(float);
};

class Kinetic {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6(int);
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
    virtual void slot21(int, void*);
};

class Work {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int, float);
};

class Motion {
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
    virtual void slot30(MotionRequest*);
};

class Collision {
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(int, CollisionParams*, int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int, int, int);
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(int, int);
};

class Module40 {
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
    virtual void slot9();
    virtual void slot10(int, int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int);
};

class OtherModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int);
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
    virtual void slot40(int);
};

struct Energy {
    char pad0[8];
    float x;
    float y;
    char pad10[0x2c];
    float acceleration;
};

struct Gravity {
    char pad0[12];
    float y;
};

struct DamagePad {
    char pad[8];
};

class Damage : public DamagePad {
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual float slot18(int);
};

#define FIGHTER_SLOT(n) virtual void slot##n();

struct FighterPad {
    char pad[0x3c];
};

class FighterSlots40 : public FighterPad {
public:
    FIGHTER_SLOT(0) FIGHTER_SLOT(1) FIGHTER_SLOT(2) FIGHTER_SLOT(3) FIGHTER_SLOT(4)
    FIGHTER_SLOT(5) FIGHTER_SLOT(6) FIGHTER_SLOT(7) FIGHTER_SLOT(8) FIGHTER_SLOT(9)
    FIGHTER_SLOT(10) FIGHTER_SLOT(11) FIGHTER_SLOT(12) FIGHTER_SLOT(13) FIGHTER_SLOT(14)
    FIGHTER_SLOT(15) FIGHTER_SLOT(16) FIGHTER_SLOT(17) FIGHTER_SLOT(18) FIGHTER_SLOT(19)
    FIGHTER_SLOT(20) FIGHTER_SLOT(21) FIGHTER_SLOT(22) FIGHTER_SLOT(23) FIGHTER_SLOT(24)
    FIGHTER_SLOT(25) FIGHTER_SLOT(26) FIGHTER_SLOT(27) FIGHTER_SLOT(28) FIGHTER_SLOT(29)
    FIGHTER_SLOT(30) FIGHTER_SLOT(31) FIGHTER_SLOT(32) FIGHTER_SLOT(33) FIGHTER_SLOT(34)
    FIGHTER_SLOT(35) FIGHTER_SLOT(36) FIGHTER_SLOT(37) FIGHTER_SLOT(38) FIGHTER_SLOT(39)
};

class FighterSlots80 : public FighterSlots40 {
public:
    FIGHTER_SLOT(40) FIGHTER_SLOT(41) FIGHTER_SLOT(42) FIGHTER_SLOT(43) FIGHTER_SLOT(44)
    FIGHTER_SLOT(45) FIGHTER_SLOT(46) FIGHTER_SLOT(47) FIGHTER_SLOT(48) FIGHTER_SLOT(49)
    FIGHTER_SLOT(50) FIGHTER_SLOT(51) FIGHTER_SLOT(52) FIGHTER_SLOT(53) FIGHTER_SLOT(54)
    FIGHTER_SLOT(55) FIGHTER_SLOT(56) FIGHTER_SLOT(57) FIGHTER_SLOT(58) FIGHTER_SLOT(59)
    FIGHTER_SLOT(60) FIGHTER_SLOT(61) FIGHTER_SLOT(62) FIGHTER_SLOT(63) FIGHTER_SLOT(64)
    FIGHTER_SLOT(65) FIGHTER_SLOT(66) FIGHTER_SLOT(67) FIGHTER_SLOT(68) FIGHTER_SLOT(69)
    FIGHTER_SLOT(70) FIGHTER_SLOT(71) FIGHTER_SLOT(72) FIGHTER_SLOT(73) FIGHTER_SLOT(74)
    FIGHTER_SLOT(75) FIGHTER_SLOT(76) FIGHTER_SLOT(77) FIGHTER_SLOT(78) FIGHTER_SLOT(79)
};

class FighterSlots120 : public FighterSlots80 {
public:
    FIGHTER_SLOT(80) FIGHTER_SLOT(81) FIGHTER_SLOT(82) FIGHTER_SLOT(83) FIGHTER_SLOT(84)
    FIGHTER_SLOT(85) FIGHTER_SLOT(86) FIGHTER_SLOT(87) FIGHTER_SLOT(88) FIGHTER_SLOT(89)
    FIGHTER_SLOT(90) FIGHTER_SLOT(91) FIGHTER_SLOT(92) FIGHTER_SLOT(93) FIGHTER_SLOT(94)
    FIGHTER_SLOT(95) FIGHTER_SLOT(96) FIGHTER_SLOT(97) FIGHTER_SLOT(98) FIGHTER_SLOT(99)
    FIGHTER_SLOT(100) FIGHTER_SLOT(101) FIGHTER_SLOT(102) FIGHTER_SLOT(103) FIGHTER_SLOT(104)
    FIGHTER_SLOT(105) FIGHTER_SLOT(106) FIGHTER_SLOT(107) FIGHTER_SLOT(108) FIGHTER_SLOT(109)
    FIGHTER_SLOT(110) FIGHTER_SLOT(111) FIGHTER_SLOT(112) FIGHTER_SLOT(113) FIGHTER_SLOT(114)
    FIGHTER_SLOT(115) FIGHTER_SLOT(116) FIGHTER_SLOT(117) FIGHTER_SLOT(118) FIGHTER_SLOT(119)
};

class FighterSlots160 : public FighterSlots120 {
public:
    FIGHTER_SLOT(120) FIGHTER_SLOT(121) FIGHTER_SLOT(122) FIGHTER_SLOT(123) FIGHTER_SLOT(124)
    FIGHTER_SLOT(125) FIGHTER_SLOT(126) FIGHTER_SLOT(127) FIGHTER_SLOT(128) FIGHTER_SLOT(129)
    FIGHTER_SLOT(130) FIGHTER_SLOT(131) FIGHTER_SLOT(132) FIGHTER_SLOT(133) FIGHTER_SLOT(134)
    FIGHTER_SLOT(135) FIGHTER_SLOT(136) FIGHTER_SLOT(137) FIGHTER_SLOT(138) FIGHTER_SLOT(139)
    FIGHTER_SLOT(140) FIGHTER_SLOT(141) FIGHTER_SLOT(142) FIGHTER_SLOT(143) FIGHTER_SLOT(144)
    FIGHTER_SLOT(145) FIGHTER_SLOT(146) FIGHTER_SLOT(147) FIGHTER_SLOT(148) FIGHTER_SLOT(149)
    FIGHTER_SLOT(150) FIGHTER_SLOT(151) FIGHTER_SLOT(152) FIGHTER_SLOT(153) FIGHTER_SLOT(154)
    FIGHTER_SLOT(155) FIGHTER_SLOT(156) FIGHTER_SLOT(157) FIGHTER_SLOT(158) FIGHTER_SLOT(159)
};

class FighterSlots186 : public FighterSlots160 {
public:
    FIGHTER_SLOT(160) FIGHTER_SLOT(161) FIGHTER_SLOT(162) FIGHTER_SLOT(163) FIGHTER_SLOT(164)
    FIGHTER_SLOT(165) FIGHTER_SLOT(166) FIGHTER_SLOT(167) FIGHTER_SLOT(168) FIGHTER_SLOT(169)
    FIGHTER_SLOT(170) FIGHTER_SLOT(171) FIGHTER_SLOT(172) FIGHTER_SLOT(173) FIGHTER_SLOT(174)
    FIGHTER_SLOT(175) FIGHTER_SLOT(176) FIGHTER_SLOT(177) FIGHTER_SLOT(178) FIGHTER_SLOT(179)
    FIGHTER_SLOT(180) FIGHTER_SLOT(181) FIGHTER_SLOT(182) FIGHTER_SLOT(183) FIGHTER_SLOT(184)
    virtual void* slot185();
};

#undef FIGHTER_SLOT

#define CONTROLLER_SLOT(n) virtual void slot##n();

class Controller {
public:
    CONTROLLER_SLOT(0) CONTROLLER_SLOT(1) CONTROLLER_SLOT(2) CONTROLLER_SLOT(3) CONTROLLER_SLOT(4)
    CONTROLLER_SLOT(5) CONTROLLER_SLOT(6) CONTROLLER_SLOT(7) CONTROLLER_SLOT(8) CONTROLLER_SLOT(9)
    CONTROLLER_SLOT(10) CONTROLLER_SLOT(11) CONTROLLER_SLOT(12) CONTROLLER_SLOT(13) CONTROLLER_SLOT(14)
    CONTROLLER_SLOT(15) CONTROLLER_SLOT(16) CONTROLLER_SLOT(17) CONTROLLER_SLOT(18) CONTROLLER_SLOT(19)
    CONTROLLER_SLOT(20) CONTROLLER_SLOT(21) CONTROLLER_SLOT(22) CONTROLLER_SLOT(23) CONTROLLER_SLOT(24)
    CONTROLLER_SLOT(25) CONTROLLER_SLOT(26) CONTROLLER_SLOT(27) CONTROLLER_SLOT(28) CONTROLLER_SLOT(29)
    CONTROLLER_SLOT(30) CONTROLLER_SLOT(31) CONTROLLER_SLOT(32) CONTROLLER_SLOT(33) CONTROLLER_SLOT(34)
    CONTROLLER_SLOT(35) CONTROLLER_SLOT(36) CONTROLLER_SLOT(37) CONTROLLER_SLOT(38) CONTROLLER_SLOT(39)
    CONTROLLER_SLOT(40) CONTROLLER_SLOT(41) CONTROLLER_SLOT(42) CONTROLLER_SLOT(43) CONTROLLER_SLOT(44)
    CONTROLLER_SLOT(45) CONTROLLER_SLOT(46) CONTROLLER_SLOT(47)
    virtual void slot48(float, float, float, int, int, int, int);
};

#undef CONTROLLER_SLOT

struct Module04Pad {
    char pad[8];
};

class Module04 : public Module04Pad {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual void slot32();
    virtual int slot33(int);
};

struct Modules {
    char pad0[4];
    Module04* module04;
    Motion* motion;
    Posture* posture;
    char pad10[0x10];
    Collision* collision;
    char pad24[0x14];
    Damage* damage;
    char pad3c[4];
    Module40* module40;
    char pad44[0x10];
    OtherModule* module54;
    OtherModule* module58;
    Controller* controller;
    char pad60[4];
    Work* work;
    char pad68[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad0[8];
    void* object;
    char pad0c[0xcc];
    Modules* modules;
};

#define VCALL(obj, offset, type) \
    ((type)((*(void***)(obj))[(offset) / 4]))

typedef float (*FloatInt)(void*, int);
typedef void (*Void0)(void*);

extern "C" void fn_27_187BB8(void*, Accesser* self) {
    Modules* modules = self->modules;
    Work* work = modules->work;
    Posture* posture = modules->posture;
    Kinetic* kinetic = modules->kinetic;
    Motion* motion = modules->motion;
    soModuleAccesser* accesser = (soModuleAccesser*)self;

    float lr = posture->slot9();
    Vec2f speed;
    float initialSpeed = soValueAccesser::getConstantFloat(accesser, 0xd65, 0);
    speed.m_x = initialSpeed * lr;
    speed.m_y = soValueAccesser::getConstantFloat(accesser, 0xd66, 0);

    kinetic->slot21(0, self);
    Energy* energy = (Energy*)__dynamic_cast(
        kinetic->slot6(2),
        0, lbl_27_data_2E380, lbl_27_data_CDF8, 1);
    Gravity* gravity = (Gravity*)__dynamic_cast(
        kinetic->slot6(1),
        0, lbl_27_data_2E430, lbl_27_data_CDF8, 1);

    float scale = 1.0f -
        soValueAccesser::getConstantFloat(accesser, 0xd72, 0);
    Damage* damage = self->modules->damage;
    float amount = damage->slot18(0);
    if (amount > 100.0f)
        amount = 100.0f;
    scale *= 0.01f * amount;
    float acceleration = soValueAccesser::getConstantFloat(accesser, 0xbd3, 0);

    float adjustedAcceleration = (1.0f - scale) * acceleration;
    float verticalSpeed = speed.m_y;
    Vec2f horizontal(speed.m_x, 0.0f);
    energy->x = horizontal.m_x;
    energy->y = horizontal.m_y;
    energy->acceleration = adjustedAcceleration;
    gravity->y = verticalSpeed;
    self->modules->work->slot13(0x21000004, adjustedAcceleration);

    float clatter1 = soValueAccesser::getConstantFloat(accesser, 0xd6a, 0);
    float clatter2 = soValueAccesser::getConstantFloat(accesser, 0xd6b, 0);
    float clatter3 = soValueAccesser::getConstantFloat(accesser, 0xd6c, 0);
    void* fighter = __dynamic_cast(
        self->object, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    void* owner = ((FighterSlots186*)fighter)->slot185();
    clatter1 *= fn_27_112E48(owner);
    typedef void (*Clatter)(void*, float, float, float, unsigned char,
                            int, unsigned long, bool);
    Controller* controller = self->modules->controller;
    controller->slot48(clatter1, clatter2, clatter3, 0, -1, 0, 0);

    self->modules->module54->slot40(0);
    posture->slot10();
    posture->slot19();
    float value = soValueAccesser::getConstantFloat(accesser, 0xd69, 0);
    work->slot13(0x21000006, value);
    float postureValue = posture->slot22();
    work->slot13(0x21000007, postureValue);
    float reduction = 1.0f - soValueAccesser::getConstantFloat(accesser, 0xd68, 0);
    posture->slot23(reduction * postureValue);

    ((FighterSlots186*)self->object)->slot43();

    float reciprocal = 1.0f /
        soValueAccesser::getConstantFloat(accesser, 0xc18, 0);
    CollisionParams params;
    params.a = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc19, 0);
    params.b = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc1a, 0);
    params.c = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc1b, 0);
    params.d = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc1c, 0);
    params.e = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc1d, 0);
    params.f = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc1e, 0);
    params.g = reciprocal * soValueAccesser::getConstantFloat(accesser, 0xc1f, 0);

    Module04* module04 = self->modules->module04;
    params.id = module04->slot33(0x130);
    params.field9 = 0;
    params.field11 = 1;
    params.field13 = 0;
    params.field15 = 1;

    self->modules->collision->slot12(0, &params, 0);
    self->modules->collision->slot18(3, 0);
    self->modules->collision->slot15(0, 0, 0);
    self->modules->module58->slot7(0);

    MotionRequest request;
    request.motion = 0x1b9;
    request.frame = 0.0f;
    request.rate = 1.0f;
    request.a = 0;
    request.b = 0;
    request.c = 0;
    request.d = 0;
    motion->slot30(&request);
    self->modules->module40->slot19(0);
    self->modules->module40->slot10(0, 0);
}
