#include <mt/mt_vector.h>
#pragma force_active on

struct Pad8 {
    int a;
    int b;
};

struct Pad3c {
    char pad[0x3c];
};

class ObjV0 {
public:
    virtual void slot0();
    virtual void slot1();
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
};

class ObjV70 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int, void*);
};

struct PairWords {
    unsigned long x;
    unsigned long y;
};

union PairValue {
    PairWords words;
    float value[2];
};

struct KineticMask {
    unsigned short bits;
    explicit KineticMask(unsigned short bits) : bits(bits) {}
};

class ObjV7c {
public:
    virtual void slot0();
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
    virtual PairWords slot13(KineticMask);
};

class ObjC {
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

class ObjC10 : public Pad8 {
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
    virtual void slot19(int, int);
};

class Obj4 : public Pad8 {
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
    virtual void slot24(int, Vec3f*);
    virtual Vec3f slot25(int);
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int, Vec3f*);
};

class Work {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int, unsigned long);
    virtual void slot10(int, unsigned long);
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(unsigned long, float);
};

class Owner : public Pad3c {
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
    virtual int slot40();
};

struct EnergyValues {
    Vec2f speed, acceleration, brake, limit;
};

class Energy {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, Vec2f*, Vec3f*, void*, float);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();

    char pad1;
    signed char flags;
    char pad2[10];
    EnergyValues values;
};

struct Modules {
    char pad0[4];
    Obj4* m4;
    char pad1[4];
    ObjC* mc;
    ObjC10* m10;
    ObjV0* m14;
    char pad2[4];
    ObjV0* m1c;
    char pad3[0x44];
    Work* work;
    char pad4[8];
    ObjV70* m70;
    char pad5[8];
    ObjV7c* m7c;
};

struct Fighter {
    char pad[8];
    Owner* owner;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(void*, unsigned long);
void fn_27_3C59C4(int, void*);
void fn_27_3C5BC4(int, void*);
void fn_27_89DAC(int, void*, float);

extern char lbl_27_data_2E5F8[];
extern char lbl_27_data_2E430[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_data_A2010[];
extern const float lbl_27_data_A2020[];
extern const float lbl_27_rodata_8080[];
}

inline void initializeEnergy(Fighter* fighter, const float* k, Vec3f& rotation) {
    Energy* energy = (Energy*)__dynamic_cast(
        fighter->modules->m7c->slot6(3), 0,
        lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    __dynamic_cast(fighter->modules->m7c->slot6(1), 0,
                   lbl_27_data_2E430, lbl_27_data_CDF8, 1);

    PairValue v8;
    v8.words = fighter->modules->m7c->slot13(KineticMask(1));
    energy->slot13();

    rotation.m_x = k[1];
    rotation.m_y = k[1];
    rotation.m_z = k[1];
    energy->slot5(0, &Vec2f(v8.value[0], k[1]), &rotation, fighter, v8.value[0]);

    energy->values.speed = Vec2f(k[1], k[1]);
    energy->values.acceleration = Vec2f(k[1], k[1]);
    energy->values.brake = Vec2f(k[1], k[1]);
    energy->values.limit = Vec2f(k[3], k[3]);
    energy->flags |= 0x80;
    fn_27_89DAC(1, fighter, k[1]);
}

extern "C" void fn_27_3C4D4C(int self, Fighter* fighter) {
    const float* k = lbl_27_rodata_8080;
    int state = fighter->modules->m14->slot3();
    int prev = fighter->modules->work->slot4(0x20000008);
    int flag = 1;

    {
        Vec3f v7c;
        v7c.m_x = k[2];
        v7c.m_y = k[2];
        v7c.m_z = k[2];

        int idx = fighter->modules->work->slot4(0x20000002);
        if (idx >= 0 && idx < 4) {
            v7c.m_x = k[2];
            v7c.m_y *= lbl_27_data_A2010[idx];
            v7c.m_z *= lbl_27_data_A2020[idx];
            fighter->modules->work->slot9(1, 0x20000002);
        } else {
            v7c.m_x = k[2];
            v7c.m_y = k[2];
            v7c.m_z = k[2];
        }

        int kind = fighter->owner->slot40();
        Obj4* model = fighter->modules->m4;
        int which = kind == 5 ? 0x196 : 3;
        model->slot24(which, &v7c);
    }

    float f30 = fighter->modules->work->slot12(0x21000006);
    float f31 = fighter->modules->work->slot12(0x2100000A);
    float product = k[11] * fn_27_192278(fighter, 0xFAC);
    float var = f30 + product * f31;

    while (var < k[1]) {
        var += k[6];
    }
    while (var > k[6]) {
        var -= k[6];
    }

    fighter->modules->work->slot13(0x21000006, var);
    fighter->modules->work->slot10(1, 0x20000000);

    if (fighter->modules->work->slot4(0x20000000) <= 0) {
        fighter->modules->work->slot10(0, 0x20000000);
        float g = fighter->modules->work->slot12(0x2100000A);
        fighter->modules->work->slot13(0x2100000A, -g);
        fighter->modules->m1c->slot4();

        if (fighter->owner->slot40() == 5) {
            fighter->modules->m70->slot3(0x18A, fighter);
        } else {
            fighter->modules->m70->slot3(0x11C, fighter);
        }
        flag = 0;
    }

    if (state == 0) {
        if (state != prev) {
            Vec3f rotation;
            initializeEnergy(fighter, k, rotation);
        }

        fn_27_3C59C4(self, fighter);
        PairValue v9;
        v9.words = fighter->modules->m7c->slot13(KineticMask(1));

        if (v9.value[0] > fn_27_192278(fighter, 0xFAD)) {
            fighter->modules->m10->slot19(1, 0);
        } else {
            fighter->modules->m10->slot19(2, 0);
        }
    } else if (state != prev) {
        fn_27_3C5BC4(self, fighter);
    }

    if (flag != 0) {
        int id = fighter->owner->slot40() == 5 ? 0x197 : 4;

        int id2;
        Vec3f v64 = fighter->modules->m4->slot25(id);
        if (k[3] == fighter->modules->mc->slot9()) {
            v64.m_y = k[4];
        } else {
            v64.m_y = k[1];
        }
        fighter->modules->m4->slot29(id, &v64);

        float f31b = fighter->modules->work->slot12(0x21000006);
        id2 = fighter->owner->slot40() == 5 ? 0x197 : 4;

        Vec3f v58 = fighter->modules->m4->slot25(id2);
        v58.m_x = k[7] * f31b;
        fighter->modules->m4->slot29(id2, &v58);
    }

    fighter->modules->work->slot5(state, 0x20000008);
}
