#include <mt/mt_vector.h>
#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

struct Cmd {
    int id;
    float a;
    float b;
    char c0;
    char c1;
    char c2;
    char c3;
};

class ObjX {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3f getPos();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual float getF();
};

class ObjA {
public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void setF(float);
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual int getI();
    virtual void q22();
    virtual void q23();
    virtual void q24();
    virtual void q25();
    virtual void q26();
    virtual void q27();
    virtual void q28();
    virtual void q29();
    virtual void callP(void*);
};

struct Pad8 {
    int a;
    int b;
};

class ObjW : public Pad8 {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void callW(int, int);
};

struct Data {
    char pad0[8];
    ObjA* a8;
    ObjX* xc;
    ObjW* w10;
};

struct Accesser {
    char pad[0xd8];
    Data* d8;
};

struct Arg {
    char pad0[8];
    float x;
    float y;
    char pad1[8];
    float f18;
    char pad2[4];
    unsigned char b20;
};

extern "C" {
void fn_27_176ED4(void* self, void* acc, float x, float y);
void fn_27_194458(void* acc, Vec2* out);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned long id, unsigned long idx);
extern const float lbl_27_rodata_2308[];
extern const float lbl_27_rodata_22F0;
}

extern "C" void fn_27_177608(void* self, Accesser* acc, Arg* arg) {
    const float* k = lbl_27_rodata_2308;
    Vec3f sp20 = acc->d8->xc->getPos();
    Vec2 sp8;
    float f30 = k[2];
    int r30 = 0x17f;

    fn_27_176ED4(self, acc, arg->x, arg->y);
    getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xd16, 0);
    fn_27_194458(acc, &sp8);
    if (k[3] != sp8.x) {
        if (sp8.y > k[3]) {
            int r29 = 0;
            if (arg->b20 != 0) {
                float f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xbe5, 0);
                if (arg->y - (sp20.m_y + f31 * acc->d8->xc->getF()) < k[4]) {
                    r29 = 1;
                }
            }
            if (r29 == 0) {
                f30 = sp8.x;
                r30 = 0x180;
            }
        } else {
            r30 = 0x181;
            f30 = sp8.x;
        }
    }
    if (arg->f18 + lbl_27_rodata_22F0 < sp20.m_y) {
        acc->d8->w10->callW(0, 0);
    } else {
        acc->d8->w10->callW(1, 0);
    }
    acc->d8->a8->setF(f30);
    if (r30 != acc->d8->a8->getI()) {
        Cmd c;
        c.id = r30;
        c.a = k[3];
        c.b = k[2];
        c.c0 = 0;
        c.c1 = 0;
        c.c2 = 0;
        c.c3 = 0;
        acc->d8->a8->callP(&c);
    }
}
