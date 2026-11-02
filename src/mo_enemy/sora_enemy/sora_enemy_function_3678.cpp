#include <so/so_value_accesser.h>
#pragma force_active on

class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0(float, unsigned long);
};

struct ModeBase {
    char pad[0x3c];
};

class Mode : public ModeBase {
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
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual unsigned long first();
    virtual unsigned long second();
};

struct Self {
    char pad0[0xb8];
    unsigned long index;
    unsigned long level;
    char pad1[0x1c];
    soModuleAccesser acc;
};

extern Mode* lbl_27_bss_5668;
extern const float lbl_41_rodata_18;

extern "C" float fn_41_3678(Self* self) {
    soWorkManageModule* work =
        self->acc.m_enumerationStart->m_workManageModule;
    float result = lbl_41_rodata_18;
    work->setFloat(result, 0x1100000c);

    if (self->level >= 1 && self->level <= 5 && self->index <= 14) {
        float (*table)[15];

        if (lbl_27_bss_5668->first() == 1) {
            table = (float (*)[15])soValueAccesser::getConstantIndefinite(
                &self->acc, 0xa81e, 0);
        } else if (lbl_27_bss_5668->second() == 1) {
            table = (float (*)[15])soValueAccesser::getConstantIndefinite(
                &self->acc, 0xa81f, 0);
        } else {
            table = (float (*)[15])soValueAccesser::getConstantIndefinite(
                &self->acc, 0xa7fa, 0);
        }

        result = *(float*)((unsigned long)table +
                           (self->level - 1) * 0x3c + self->index * 4);
        work->setFloat(result, 0x1100000c);
    }

    return result;
}
