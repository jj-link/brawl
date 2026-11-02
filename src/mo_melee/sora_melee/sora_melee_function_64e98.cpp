#include <types.h>
#pragma force_active on

struct Msg {
    s32 id;
    u8 flag;
    s32 val;
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual u32 slot4(s32, u32);
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
    virtual void slot15(s32, Msg*);
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
    virtual void slot56();
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
    virtual void slot75(s32, s32, s32, s32, s32);
};

struct SubB {
    char pad00[0x54];
    soNullable* unk54;
};

struct SubA {
    char pad00[0xd8];
    SubB* unkD8;
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
    virtual void fn_27_15604();
    virtual void fn_27_16CA8();
    virtual void fn_27_16CB0();
    virtual void fn_27_1CB80();
    virtual void fn_27_16CB8();
    virtual void fn_27_16CC0();
    virtual void fn_27_16E88();
    virtual void fn_27_16FB4();
    virtual void fn_27_170A8();
    virtual void fn_27_171D0();
    virtual void fn_27_1CB6C();
    virtual void fn_27_1CB38();
    virtual void fn_27_17334();
    virtual void fn_27_17374();
    virtual void fn_27_173A8();
    virtual void fn_27_17444();
    virtual void fn_27_17518();
    virtual void fn_27_1754C();
    virtual void fn_27_17584();
    virtual void fn_27_175FC();
    virtual void fn_27_17674();
    virtual void fn_27_17A9C();
    virtual void fn_27_17688();
    virtual void fn_27_17970();
    virtual void fn_27_17AD0();
    virtual void fn_27_17B18();
    virtual void fn_27_17B94();
    virtual void fn_27_17C10();
    virtual void fn_27_17C90();
    virtual void fn_27_17D0C();
    virtual void fn_27_17D88();
    virtual void fn_27_17E00();
    virtual void fn_27_17E78();
    virtual void fn_27_18170();
    virtual void fn_27_1838C();
    virtual void fn_27_18C40();
    virtual void fn_27_1858C();
    virtual void fn_27_18628();
    virtual void fn_27_18834();
    virtual void fn_27_18C58();
    virtual void fn_27_18A34();
    virtual void fn_27_18AD0();

    char pad04[0xc];
    SubA* unk10;
    s32 unk14;
    char pad18[0x48];
    u8 unk60;
};

extern "C" void fn_27_64E98(Class_1250* self, u32 arg1) {
    self->unk60 = 1;
    if (arg1 != 0xFFFFFFFF) {
        if (self->unk10->unkD8->unk54->slot4(0, arg1) == 1) {
            self->fn_27_14A30();
            Msg msg;
            msg.id = 0x11;
            msg.flag = 0;
            msg.val = -1;
            self->unk10->unkD8->unk54->slot15(0, &msg);
            self->unk10->unkD8->unk54->slot75(0, self->unk14, msg.val, 3, 1);
        }
    }
}
