#pragma force_active on
extern "C" {
extern float lbl_27_rodata_2320;
extern const float lbl_27_rodata_2324;
}

struct Vec {
    float x;
    float y;
    float z;

    Vec(float xValue, float yValue)
        : x(xValue), y(yValue), z(lbl_27_rodata_2324) {}
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec slot4();
    virtual void slot5(Vec*);
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual unsigned int slot16();
};

class Ground {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(int, void*);
};

struct KineticBase {
    char pad[8];
};

#define KINETIC_TEN(n) \
    virtual void f##n##0(); \
    virtual void f##n##1(); \
    virtual void f##n##2(); \
    virtual void f##n##3(); \
    virtual void f##n##4(); \
    virtual void f##n##5(); \
    virtual void f##n##6(); \
    virtual void f##n##7(); \
    virtual void f##n##8(); \
    virtual void f##n##9();

struct Kinetic : KineticBase {
    KINETIC_TEN(0)
    KINETIC_TEN(1)
    KINETIC_TEN(2)
    KINETIC_TEN(3)
    KINETIC_TEN(4)
    KINETIC_TEN(5)
    KINETIC_TEN(6)
    KINETIC_TEN(7)
    KINETIC_TEN(8)
    KINETIC_TEN(9)
    KINETIC_TEN(10)
    virtual void f110();
    virtual void f111();
    virtual unsigned int query(int);
};

#undef KINETIC_TEN

struct Modules {
    char pad[8];
    soNullable* motion;
    soNullable* posture;
    Kinetic* kinetic;
    soNullable* status;
    char pad18[0x58];
    Ground* ground;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Input {
    char pad[8];
    float x;
    float y;
};

extern "C" void fn_27_177E8C(void*, Accesser* a, Input* in) {
    Vec target(in->x, in->y);
    const Vec& pos = a->modules->posture->slot4();

    if (a->modules->motion->slot16() == 1U) {
        a->modules->posture->slot5(&target);
        if (a->modules->kinetic->query(0) == 1U) {
            a->modules->status->slot6(0, 0);
            a->modules->ground->d(0, a);
        } else {
            a->modules->status->slot6(2, 0);
            a->modules->ground->d(14, a);
        }
    } else if (lbl_27_rodata_2320 + target.y < pos.y) {
        a->modules->status->slot6(2, 0);
        a->modules->ground->d(14, a);
    }
}
