#include <mt/mt_vector.h>

#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int slot4(int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(int);
    virtual void slot13(int, float);
    virtual void slot14();
    virtual void slot15(Vec3f*, int);
    virtual float slot16();
};

class Status {
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
    virtual int slot16();
};

struct MotionBase {
    char pad[8];
};

class Motion : public MotionBase {
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
    virtual void slot29(int, Vec3f*);
    virtual void slot30();
    virtual void slot31(int, Vec3f*);
};

union Pair { unsigned long long bits; struct { float x, y; } v; };

class Kinetic {
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
    virtual unsigned long long slot13(short*);
};

struct Modules {
    char pad0[4];
    Motion* motion;
    char pad1[4];
    soNullable* posture;
    char pad2[0x4c];
    soNullable* other;
    char pad3[4];
    soNullable* work;
    char pad4[8];
    Status* status;
    char pad5[8];
    Kinetic* kinetic;
};

struct Owner {
    char pad[8];
    void* object;
    char pad2[0xcc];
    Modules* modules;
};

struct Param {
    char pad[0x44];
    float step;
};

struct Link {
    char pad[0x4870];
    Param* param;
};

struct KineticId {
    short id;
    short padding;
};

static inline void setCount(int value, soNullable* work) {
    work->slot5(value, 0x20000000);
}

static inline void setSpeed(Pair value, soNullable* work) {
    work->slot13(0x11000002, value.v.x);
    work->slot13(0x11000003, value.v.y);
}

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_31CA6C(void*, Owner*);
void fn_27_31CF8C(void*, Owner*);
void fn_27_31CBA4(void*, Owner*);
void fn_27_31CDD8(void*, Owner*);

extern char lbl_27_data_48E80[];
extern char lbl_27_data_248[];
extern const float lbl_27_rodata_74F0;
}

extern "C" void fn_27_31B0F8(void* self, Owner* owner) {
    Pair result;
    Pair p;
    Pair raw;
    Vec3f velocity;
    Param* param = ((Link*)__dynamic_cast(
        owner->object, 0x3c, lbl_27_data_48E80, lbl_27_data_248, 1))->param;
    soNullable* work = owner->modules->work;
    int status = owner->modules->status->slot16();

    if (status == 5) {
        fn_27_31CA6C(self, owner);
        fn_27_31CF8C(self, owner);
        fn_27_31CBA4(self, owner);

        soNullable* w = owner->modules->work;
        Motion* m = owner->modules->motion;
        float a = w->slot12(0x21000000);
        float b = w->slot12(0x21000002);
        float c = w->slot12(0x21000001);
        float d = w->slot12(0x21000003);

        Vec3f u;
        Vec3f v(lbl_27_rodata_74F0, c, a);
        m->slot31(4, &v);
        u.m_x = b;
        u.m_y = lbl_27_rodata_74F0;
        u.m_z = d;
        m->slot29(4, &u);
    } else if ((unsigned)status <= 1) {
        float a = owner->modules->posture->slot9();
        float b = owner->modules->other->slot16();
        unsigned int n = work->slot4(0x20000000);
        if (b * a < lbl_27_rodata_74F0)
            ++n;
        else
            n = 0;
        setCount(n, work);

        fn_27_31CA6C(self, owner);
        fn_27_31CDD8(self, owner);
        fn_27_31CBA4(self, owner);

        soNullable* w = owner->modules->work;
        Motion* m = owner->modules->motion;
        float x = w->slot12(0x21000000);
        float y = w->slot12(0x21000002);
        float z = w->slot12(0x21000001);
        float q = w->slot12(0x21000003);

        Vec3f u;
        Vec3f v(lbl_27_rodata_74F0, z, x);
        m->slot31(4, &v);
        u.m_x = y;
        u.m_y = lbl_27_rodata_74F0;
        u.m_z = q;
        m->slot29(4, &u);
    } else if ((unsigned)(status - 3) <= 1) {
        fn_27_31CBA4(self, owner);

        soNullable* w = owner->modules->work;
        Motion* m = owner->modules->motion;
        float x = w->slot12(0x21000000);
        float y = w->slot12(0x21000002);
        float z = w->slot12(0x21000001);
        float q = w->slot12(0x21000003);

        Vec3f u;
        Vec3f v(lbl_27_rodata_74F0, z, x);
        m->slot31(4, &v);
        u.m_x = y;
        u.m_y = lbl_27_rodata_74F0;
        u.m_z = q;
        m->slot29(4, &u);
    } else if (status == 6) {
        KineticId id;
        id.id = -1;
        p.bits = owner->modules->kinetic->slot13(&id.id);
        float ky = p.v.y;
        bool positive = ky > lbl_27_rodata_74F0;
        if (positive) {
            float speed = work->slot12(0x11000004);
            if (speed > lbl_27_rodata_74F0) {
                speed -= param->step;
                if (speed < lbl_27_rodata_74F0)
                    speed = lbl_27_rodata_74F0;
            } else if (speed < lbl_27_rodata_74F0) {
                speed += param->step;
                if (speed > lbl_27_rodata_74F0)
                    speed = lbl_27_rodata_74F0;
            }

            work->slot13(0x11000004, speed);
            velocity.m_x = -speed;
            velocity.m_y = lbl_27_rodata_74F0;
            velocity.m_z = lbl_27_rodata_74F0;
            owner->modules->posture->slot15(&velocity, 0);
        }
    }

    short id = -1;
    raw.bits = owner->modules->kinetic->slot13(&id);
    result = raw;
    work->slot13(0x11000002, result.v.x);
    work->slot13(0x11000003, result.v.y);
}
