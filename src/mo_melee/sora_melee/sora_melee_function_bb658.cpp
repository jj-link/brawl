#pragma force_active on
#include <types.h>
#define D(n) virtual void d##n();
struct Msg { u32 id; u8 a; u8 b; };
struct Elem;
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Elem* slot1(int);
    virtual void slot2();
    virtual int slot3();
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
    virtual void slot16(int, void*, int);
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
};
struct Obj4 {
    char pad[0x3c];
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39) D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49) D(50) D(51) D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59) D(60) D(61) D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69) D(70) D(71) D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79) D(80) D(81) D(82) D(83) D(84) D(85) D(86) D(87) D(88) D(89) D(90) D(91) D(92) D(93) D(94) D(95) D(96) D(97) D(98) D(99) D(100) D(101) D(102) D(103) D(104) D(105) D(106) D(107) D(108) D(109) D(110) D(111) D(112) D(113) D(114) D(115) D(116) D(117) D(118) D(119) D(120) D(121) D(122) D(123) D(124) D(125) D(126) D(127) D(128) D(129) D(130) D(131) D(132) D(133) D(134)
    virtual void change(u8);
};
struct Elem {
    char pad0[4]; Obj4* obj; char pad8[8];
    u8 bit7 : 1; u8 bit6 : 1; u8 low : 6;
    bool isEnabled() const { return bit7; }
    bool isIndex(u32 index) const { return index == low; }
};
struct Mid_d8 { char pad[0x54]; Object_vptr_0* unk54; };
struct Mid68 { char pad[0xd8]; Mid_d8* unkD8; };
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_B81C4();
    virtual void fn_27_B8360();
    virtual void fn_27_B83E4();
    virtual void fn_27_B8674();
    virtual void fn_27_B86B0();
    virtual void fn_27_B87B8();
    virtual void fn_27_B88AC();
    virtual void fn_27_B8A98();
    virtual void fn_27_B8B44();
    virtual void fn_27_BC19C();
    virtual void fn_27_B91FC();
    virtual void fn_27_B86D4();
    virtual void fn_27_BE4F0();
    virtual void fn_27_B83F4();
    virtual void fn_27_B8434();
    virtual void fn_27_B8468();
    virtual void fn_27_B849C();
    virtual void fn_27_B84D0();
    virtual void fn_27_B8548();
    virtual void fn_27_B8594();
    virtual void fn_27_B85E0();
    virtual void fn_27_BE4E8();
    virtual void fn_27_BE4E0();
    virtual void fn_27_BE4D8();
    virtual void fn_27_B8648();
    virtual void fn_27_B8780();
    virtual void fn_27_BC0A4();
    virtual void fn_27_BC0BC();
    virtual void fn_27_B9918();
    virtual void fn_27_B9D20();
    virtual void fn_27_BA1C8();
    virtual void fn_27_BA600();
    virtual void fn_27_BA514();
    virtual void fn_27_BA594();
    virtual void fn_27_BA714();
    virtual void fn_27_BA9B8();
    virtual void fn_27_BAA38();
    virtual void fn_27_BAAAC();
    virtual void fn_27_BAB24();
    virtual void fn_27_BAC38();
    virtual void fn_27_BACD4();
    virtual void fn_27_BB040();
    virtual void fn_27_BB0C0();
    virtual void fn_27_BB14C();
    virtual void fn_27_B9108();
    virtual void fn_27_B9878();
    virtual void fn_27_B97FC();
    virtual void fn_27_B9810();
    virtual void fn_27_BB658(u8, u8);
    char pad4[0x3c]; Object_vptr_0* unk40;
    char pad44[0x1e]; u8 flag62; char pad63[5]; Mid68* unk68;
};
extern "C" void fn_27_BB658(soNullable* self, u8 arg1, u32 arg2) {
    u32 i;
    if (arg2 == 0xFF) {
        for (i = 0; i < 3U; i++) self->fn_27_BB658(arg1, (u8)i);
        return;
    }
    i = (u32)self + arg2;
    if (arg1 != *(u8*)(i + 0x62)) {
        if (arg2 == 2) {
            Msg msg;
            msg.b = arg1;
            msg.id = 0x37;
            msg.a = 0;
            self->unk68->unkD8->unk54->slot16(-1, &msg, 0);
        } else {
            int count = self->unk40->slot3();
            for (int i = 0; i < count; i++) {
                Elem* e = self->unk40->slot1(i);
                if (e->isIndex(arg2) && arg1 != e->isEnabled()) {
                    e->bit7 = arg1;
                    e->obj->change(arg1);
                }
            }
        }
        *(u8*)(i + 0x62) = arg1;
    }
}