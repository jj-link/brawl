#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

struct KineticSlots {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* getEnergy(int);
};

struct StatusSlots {
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
    virtual int getStatusKind();
};

struct SituationSlots {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int getSituation();
};

struct EnergySlots {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void reset(int, const void*, const void*, void*);
};

struct WorkSlots {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void set(int, int);
};

struct KindPrefix {
    char pad[0x3C];
};

struct KindSlots : KindPrefix {
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
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual int getKind();
};

extern "C" {
extern const char lbl_119_data_5CF4[];
extern const char lbl_119_data_5C14[];
extern const char lbl_119_data_5C58[];
extern const char lbl_119_data_1374[];
extern const char lbl_119_data_6D0[];
extern const char lbl_119_data_1E14[];
extern const char lbl_119_data_5D44[];
extern const float lbl_119_rodata_38;
extern const float lbl_119_rodata_3C;

void* __dynamic_cast(void*, long, const void*, const void*, short);
float* fn_119_8F00(float*, float, float, float);
void fn_119_B6CC(Vec2&, const Vec2&);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
void fn_27_15CF5C(void*, float);
void fn_27_89DAC(int, void*);
}

extern "C" void fn_119_C8DC(void*, void* accesser) {
    char* a = (char*)accesser;
    void* kinetic = *(void**)(*(char**)(a + 0xD8) + 0x7C);
    __dynamic_cast(((KineticSlots*)kinetic)->getEnergy(1), 0,
                   lbl_119_data_5CF4, lbl_119_data_1374, 1);

    kinetic = *(void**)(*(char**)(a + 0xD8) + 0x7C);
    __dynamic_cast(((KineticSlots*)kinetic)->getEnergy(3), 0,
                   lbl_119_data_5C14, lbl_119_data_1374, 1);

    kinetic = *(void**)(*(char**)(a + 0xD8) + 0x7C);
    void* energy = __dynamic_cast(
        ((KineticSlots*)kinetic)->getEnergy(0), 0,
        lbl_119_data_5C58, lbl_119_data_1374, 1);

    int status =
        ((StatusSlots*)*(void**)(*(char**)(a + 0xD8) + 0x70))->getStatusKind();

    switch (status) {
    case 0x114: {
        void* obj = __dynamic_cast(*(void**)(a + 8), 0x3C,
                                   lbl_119_data_6D0, lbl_119_data_1E14, 1);
        int kind = ((KindSlots*)obj)->getKind();
        void* param = g_ftCommonDataAccesser.getParam((ftKind)kind);

        kinetic = *(void**)(*(char**)(a + 0xD8) + 0x7C);
        void* energy2 = __dynamic_cast(
            ((KineticSlots*)kinetic)->getEnergy(2), 0,
            lbl_119_data_5D44, lbl_119_data_1374, 1);

        void* situation = *(void**)(*(char**)(a + 0xD8) + 0x14);
        if (((SituationSlots*)situation)->getSituation() == 0) {
            float zero = lbl_119_rodata_38;
            Vec2 first;
            first.x = zero;
            first.y = zero;
            float rot1[3];
            float* rotResult1 = fn_119_8F00(rot1, zero, zero, zero);
            ((EnergySlots*)energy2)->reset(0x0B, &first, rotResult1, accesser);
            void* work = *(void**)(*(char**)(a + 0xD8) + 0x64);
            ((WorkSlots*)work)->set(0, 0x20000000);
        } else {
            float zero = lbl_119_rodata_38;
            Vec2 second;
            second.x = zero;
            second.y = zero;
            float rot2[3];
            float* rotResult2 = fn_119_8F00(rot2, zero, zero, zero);
            ((EnergySlots*)energy2)->reset(0, &second, rotResult2, accesser);
            void* work = *(void**)(*(char**)(a + 0xD8) + 0x64);
            ((WorkSlots*)work)->set(2, 0x20000000);
        }

        float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xFB3, 0);
        float value = *(float*)((char*)param + 0x74) * scale;
        fn_27_15CF5C(energy2, value);

        Vec2 speed;
        speed.x = *(float*)((char*)param + 0x7C);
        speed.y = lbl_119_rodata_3C;
        fn_119_B6CC(*(Vec2*)((char*)energy2 + 0x18), speed);

        ((unsigned char*)energy2)[5] |= 0x80;
        fn_27_89DAC(3, accesser);
        fn_27_89DAC(1, accesser);
        fn_27_89DAC(0, accesser);
        break;
    }

    case 0x11E: {
        void* situation = *(void**)(*(char**)(a + 0xD8) + 0x14);
        if (((SituationSlots*)situation)->getSituation() == 0) {
            float zero = lbl_119_rodata_38;
            Vec2 first;
            first.x = zero;
            first.y = zero;
            float rot1[3];
            float* rotResult1 = fn_119_8F00(rot1, zero, zero, zero);
            ((EnergySlots*)energy)->reset(3, &first, rotResult1, accesser);
        } else {
            float zero = lbl_119_rodata_38;
            Vec2 second;
            second.x = zero;
            second.y = zero;
            float rot2[3];
            float* rotResult2 = fn_119_8F00(rot2, zero, zero, zero);
            ((EnergySlots*)energy)->reset(5, &second, rotResult2, accesser);
        }

        ((unsigned char*)energy)[5] |= 0x80;
        fn_27_89DAC(3, accesser);
        fn_27_89DAC(2, accesser);
        fn_27_89DAC(1, accesser);
        break;
    }

    case 0x120:
        fn_27_89DAC(2, accesser);
        fn_27_89DAC(0, accesser);
        break;
    }
}
