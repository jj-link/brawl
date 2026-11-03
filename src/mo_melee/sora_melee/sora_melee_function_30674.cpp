#include <types.h>

#pragma force_active on

struct Context;

class Result {
public:
    virtual void isNull();
    virtual u32 slot1(Context*);
};

struct DispatchBase {
    char pad[8];
};

#define DECL_SLOT(n) virtual void slot##n();

class Dispatch : public DispatchBase {
public:
    DECL_SLOT(0)   DECL_SLOT(1)   DECL_SLOT(2)   DECL_SLOT(3)
    DECL_SLOT(4)   DECL_SLOT(5)   DECL_SLOT(6)   DECL_SLOT(7)
    DECL_SLOT(8)   DECL_SLOT(9)   DECL_SLOT(10)  DECL_SLOT(11)
    DECL_SLOT(12)  DECL_SLOT(13)  DECL_SLOT(14)  DECL_SLOT(15)
    DECL_SLOT(16)  DECL_SLOT(17)  DECL_SLOT(18)  DECL_SLOT(19)
    DECL_SLOT(20)  DECL_SLOT(21)  DECL_SLOT(22)  DECL_SLOT(23)
    DECL_SLOT(24)  DECL_SLOT(25)  DECL_SLOT(26)  DECL_SLOT(27)
    DECL_SLOT(28)  DECL_SLOT(29)  DECL_SLOT(30)  DECL_SLOT(31)
    DECL_SLOT(32)  DECL_SLOT(33)  DECL_SLOT(34)  DECL_SLOT(35)
    DECL_SLOT(36)  DECL_SLOT(37)  DECL_SLOT(38)  DECL_SLOT(39)
    DECL_SLOT(40)  DECL_SLOT(41)  DECL_SLOT(42)  DECL_SLOT(43)
    DECL_SLOT(44)  DECL_SLOT(45)  DECL_SLOT(46)  DECL_SLOT(47)
    DECL_SLOT(48)  DECL_SLOT(49)  DECL_SLOT(50)  DECL_SLOT(51)
    DECL_SLOT(52)  DECL_SLOT(53)  DECL_SLOT(54)  DECL_SLOT(55)
    DECL_SLOT(56)  DECL_SLOT(57)  DECL_SLOT(58)  DECL_SLOT(59)
    DECL_SLOT(60)  DECL_SLOT(61)  DECL_SLOT(62)  DECL_SLOT(63)
    DECL_SLOT(64)  DECL_SLOT(65)  DECL_SLOT(66)  DECL_SLOT(67)
    DECL_SLOT(68)  DECL_SLOT(69)  DECL_SLOT(70)  DECL_SLOT(71)
    DECL_SLOT(72)  DECL_SLOT(73)  DECL_SLOT(74)  DECL_SLOT(75)
    DECL_SLOT(76)  DECL_SLOT(77)  DECL_SLOT(78)  DECL_SLOT(79)
    DECL_SLOT(80)  DECL_SLOT(81)  DECL_SLOT(82)  DECL_SLOT(83)
    DECL_SLOT(84)  DECL_SLOT(85)  DECL_SLOT(86)  DECL_SLOT(87)
    DECL_SLOT(88)  DECL_SLOT(89)  DECL_SLOT(90)  DECL_SLOT(91)
    DECL_SLOT(92)  DECL_SLOT(93)  DECL_SLOT(94)  DECL_SLOT(95)
    DECL_SLOT(96)  DECL_SLOT(97)  DECL_SLOT(98)  DECL_SLOT(99)
    DECL_SLOT(100) DECL_SLOT(101) DECL_SLOT(102) DECL_SLOT(103)
    DECL_SLOT(104) DECL_SLOT(105) DECL_SLOT(106) DECL_SLOT(107)
    DECL_SLOT(108) DECL_SLOT(109) DECL_SLOT(110) DECL_SLOT(111)
    DECL_SLOT(112) DECL_SLOT(113) DECL_SLOT(114) DECL_SLOT(115)
    DECL_SLOT(116) DECL_SLOT(117) DECL_SLOT(118) DECL_SLOT(119)
    DECL_SLOT(120) DECL_SLOT(121) DECL_SLOT(122) DECL_SLOT(123)
    DECL_SLOT(124) DECL_SLOT(125) DECL_SLOT(126) DECL_SLOT(127)
    DECL_SLOT(128) DECL_SLOT(129) DECL_SLOT(130) DECL_SLOT(131)
    DECL_SLOT(132) DECL_SLOT(133) DECL_SLOT(134) DECL_SLOT(135)
    DECL_SLOT(136) DECL_SLOT(137) DECL_SLOT(138) DECL_SLOT(139)
    DECL_SLOT(140) DECL_SLOT(141) DECL_SLOT(142) DECL_SLOT(143)
    DECL_SLOT(144) DECL_SLOT(145) DECL_SLOT(146) DECL_SLOT(147)
    DECL_SLOT(148) DECL_SLOT(149) DECL_SLOT(150)
    virtual Result* slot151();
};

#undef DECL_SLOT

class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual void fn_27_2362C();
    virtual void fn_27_236B0();
    virtual void fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
    virtual void fn_27_2370C();
    virtual void fn_27_23728();
    virtual void fn_27_23E28();
    virtual void fn_27_23CC0();
    virtual void fn_27_25068();
    virtual void fn_27_23A9C();
    virtual void fn_27_23B18();
    virtual void fn_27_250FC();
    virtual void fn_27_250A4();
    virtual float fn_27_23BF8();
};

struct Modules {
    char pad[0x10];
    Dispatch* dispatch;
    char pad2[0x48];
    soPostureModuleImpl* posture;
};

struct Context {
    char pad[0xD8];
    Modules* modules;
};

struct State {
    char pad[8];
    s32 flags;
    u32 valueHigh : 8;
    u32 value : 8;
    u32 valueLow : 16;
    char pad2[0x61];
    u8 a;
    u8 b;
};

struct Holder {
    char pad[4];
    State* state;
};

extern "C" void fn_27_2F00C(void*, u32, u32);
extern "C" void fn_80133F64(void*);

extern float lbl_27_rodata_438;
extern float lbl_27_rodata_43C;

extern "C" void fn_27_30674(void*, Holder* holder, Context* context) {
    State* state = holder->state;
    state->a &= ~8;
    state->b &= ~0x20;
    fn_27_2F00C(holder, 0, 1);

    if (state->flags >> 24) {
        fn_80133F64(state);
    }

    state = holder->state;
    if (context->modules->dispatch->slot151()->slot1(context) == 1) {
        state->b &= ~0x20;
        state->value = 2;
    } else {
        state->b |= 0x20;
        float f = context->modules->posture->fn_27_23BF8();
        if (f > lbl_27_rodata_438) {
            state->value = 1;
        } else if (f < lbl_27_rodata_43C) {
            state->value = 0;
        } else {
            state->value = 2;
        }
    }
}
