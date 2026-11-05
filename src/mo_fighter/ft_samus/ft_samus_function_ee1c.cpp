#include <ft/ft_common_data_accesser.h>
#pragma force_active on

struct Pair {
    float x, y;
};

struct Speed {
    float x, y;
    Speed() {}
    Speed(float a, float b) : x(a), y(b) {}
};

struct Vector {
    float x, y, z;
};

struct AttributeFlag {
    unsigned short mask;
    AttributeFlag(int value) : mask(value) {}
};

struct Accesser;

class Energy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void reset(int, Speed*, Vector*, Accesser*);

    unsigned char state;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    char pad[0x12];
    Speed a;
    char pad20[8];
    Speed b;
    char pad30[12];
    float c, d;

    void disable() { enabled = 0; }
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
    virtual Pair getSum(const AttributeFlag&);
};

class Situation {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
};

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
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
    virtual void op(int);
};

class Class_CF88 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CAF0();
    virtual void fn_94_1DAE0();
    virtual void fn_94_1DAD8();
    virtual void fn_94_1DAD0();
    virtual void fn_94_1DAC8();
    virtual void fn_94_1DAC0();
    virtual void fn_94_1DAB8();
    virtual void fn_94_1DAB0();
    virtual void fn_94_1DAA8();
    virtual void fn_94_1DAA0();
    virtual void fn_94_1DA98();
    virtual void fn_94_1DA90();
    virtual void fn_94_1DA88();
    virtual void fn_94_1DA38();
    virtual void fn_94_1DA80();
    virtual void fn_94_1DA70();
    virtual void fn_94_1DA60();
    virtual void fn_94_1DA50();
};

struct Modules {
    char p0[0x14];
    Situation* situation;
    char p18[0x4c];
    Work* work;
    char p68[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Params {
    char pad[4];
    float c, a, y;
};

extern "C" {
extern const char lbl_94_data_9804[];
extern const char lbl_94_data_98E4[];
extern const char lbl_94_data_9934[];
extern const char lbl_94_data_4570[];
extern const float lbl_94_rodata_28;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Vector* fn_94_94E0(Vector*, float, float, float);
void fn_94_F174(Speed*, float, float);
void fn_94_DC68(Speed*, const Speed*);
}

extern "C" void fn_94_EE1C(void*, Accesser& a) {
    Pair speed;
    int kind = a.modules->situation->getKind();
    int flag = 1;
    Pair sum = a.modules->kinetic->getSum(AttributeFlag(flag));
    __memcpy(&speed, &sum, sizeof(speed));

    const Params& params = **reinterpret_cast<Params**>(
        reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3)) + 0x80);

    a.modules->kinetic->getEnergy(0)->disable();
    a.modules->kinetic->getEnergy(1)->disable();
    a.modules->kinetic->getEnergy(2)->disable();
    a.modules->kinetic->getEnergy(3)->disable();

    switch (kind) {
    default: {
        a.modules->work->op(0x22000012);
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            a.modules->kinetic->getEnergy(3), 0,
            lbl_94_data_9804, lbl_94_data_4570, flag));
        Speed h(speed.x, lbl_94_rodata_28);
        Vector v;
        e->reset(0, &h, fn_94_94E0(&v, lbl_94_rodata_28,
            lbl_94_rodata_28, lbl_94_rodata_28), &a);
        e->enabled = 1;
        break;
    }
    case 2: {
        speed.y = params.y;
        Energy* e = static_cast<Energy*>(__dynamic_cast(
            a.modules->kinetic->getEnergy(1), 0,
            lbl_94_data_98E4, lbl_94_data_4570, flag));
        Speed vert(lbl_94_rodata_28, speed.y);
        Vector v;
        e->reset(0, &vert, fn_94_94E0(&v, lbl_94_rodata_28,
            lbl_94_rodata_28, lbl_94_rodata_28), &a);
        e->enabled = 1;

        e = static_cast<Energy*>(__dynamic_cast(
            a.modules->kinetic->getEnergy(2), 0,
            lbl_94_data_9934, lbl_94_data_4570, flag));
        Speed h(speed.x, lbl_94_rodata_28);
        Vector v2;
        e->reset(0, &h, fn_94_94E0(&v2, lbl_94_rodata_28,
            lbl_94_rodata_28, lbl_94_rodata_28), &a);
        e->c = params.c;
        e->d = lbl_94_rodata_28;

        Speed t;
        fn_94_F174(&t, params.a, e->a.y);
        fn_94_DC68(&e->a, &t);

        Speed t2;
        fn_94_F174(&t2, params.a, e->b.y);
        fn_94_DC68(&e->b, &t2);
        e->enabled = 1;
        break;
    }
    }
}
