#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <math.h>
#pragma force_active on

class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44(float);
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24(Vec3f*, int);
    virtual void fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4();
    virtual void fn_96_23CE4();
};

class Kinetic {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual Vec2f getSumSpeed(short*);
};

class Work {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void setFloat(float, unsigned int);
};

struct Modules {
    char pad0[0xc];
    Class_CD28* posture;
    char pad1[0x54];
    Work* work;
    char pad2[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* m_enumerationStart;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" {
int fn_27_1DAE14(Object*);
extern const float lbl_96_rodata_528[];
}

extern "C" int fn_96_23808(Object* self) {
    const float* constants = lbl_96_rodata_528;
    fn_27_1DAE14(self);

    Modules* modules = self->accesser->m_enumerationStart;
    Work* work = modules->work;
    Kinetic* kinetic = modules->kinetic;
    Class_CD28* posture = modules->posture;

    short flag = 1;
    Vec2f speed = kinetic->getSumSpeed(&flag);

    float lengthSq = speed.m_x * speed.m_x + speed.m_y * speed.m_y;
    double absSq = fabs((double)lengthSq);
    float mag = (float)absSq;
    float length;
    if (mag <= constants[7]) {
        length = constants[2];
    } else {
        length = lengthSq * rsqrtf(lengthSq);
    }

    double absXd = fabs((double)speed.m_x);
    float absX = (float)absXd;
    float angle = atan2(-speed.m_y, absX);
    if (speed.m_x < constants[2]) {
        posture->fn_96_23D44(constants[1]);
        posture->fn_96_23CE4();
    }

    Vec3f rot;
    rot.m_x = constants[6] * angle;
    rot.m_y = constants[2];
    rot.m_z = constants[2];
    posture->fn_96_23D24(&rot, 0);

    work->setFloat(angle, 0x11000001);
    work->setFloat(length, 0x11000002);
    return 0;
}
