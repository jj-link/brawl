#include <types.h>
#pragma force_active on

struct Vec2f { float x, y; };
struct Vec3f { float x, y, z; };
struct Parameters { Vec2f p[4]; };

class Work {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(unsigned long);
};

class Status {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int getKind();
};

class Kinetic {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual unsigned long long getSpeed(const short*);
};

class Posture {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec3f getPos();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual float getLr();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float getScale();
};

struct Modules {
    char pad[0xc];
    Posture* posture;
    char pad1[0x54];
    Work* work;
    char pad2[8];
    Status* status;
    char pad3[8];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Output {
    char pad[0x100];
    int v100;
    int v104;
};

extern "C" {
void fn_27_13FE28(void*, const Vec3f&, float, float, const Vec2f&,
                  const Parameters&, const Parameters&, int);
extern const float lbl_27_rodata_79B8;
}

extern "C" void fn_27_358A3C(void* unused, Accesser* accesser, Output* output) {
    Work* work = accesser->modules->work;
    output->v100 = work->s4(0x10000041);
    output->v104 = work->s4(0x10000042);

    Parameters b;
    b.p[0].x = lbl_27_rodata_79B8;
    b.p[1].x = lbl_27_rodata_79B8;
    b.p[2].x = lbl_27_rodata_79B8;
    b.p[3].x = lbl_27_rodata_79B8;
    b.p[0].y = lbl_27_rodata_79B8;
    b.p[1].y = lbl_27_rodata_79B8;
    b.p[2].y = lbl_27_rodata_79B8;
    b.p[3].y = lbl_27_rodata_79B8;
    Parameters a;
    a.p[0].x = lbl_27_rodata_79B8;
    a.p[1].x = lbl_27_rodata_79B8;
    a.p[2].x = lbl_27_rodata_79B8;
    a.p[3].x = lbl_27_rodata_79B8;
    a.p[0].y = lbl_27_rodata_79B8;
    a.p[1].y = lbl_27_rodata_79B8;
    a.p[2].y = lbl_27_rodata_79B8;
    a.p[3].y = lbl_27_rodata_79B8;

    Posture* posture;
    int kind = 0;
    if (accesser->modules->status->getKind() != 0x10b)
        kind = 0x160015;

    short flag = -1;
    Kinetic* kinetic = accesser->modules->kinetic;
    Vec2f speed;
    *(unsigned long long*)&speed = kinetic->getSpeed(&flag);

    posture = accesser->modules->posture;
    fn_27_13FE28(output, posture->getPos(), posture->getScale(),
                 posture->getLr(), speed, a, b, kind);
}
