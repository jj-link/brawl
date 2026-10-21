#pragma force_active on

typedef signed int s32;

extern float lbl_27_rodata_7870;
extern float lbl_27_rodata_7878;

struct Vec {
    float x, y, z;

    Vec(float v) : x(v), y(v), z(v) {}
};

class A {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec s4();
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
    virtual void s15(float* out, s32 flag);
};

class B {
public:
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6(s32 mode, const Vec& p, const Vec& q,
                    s32 x, s32 y, float f);
};

struct Sub {
    char pad0[0xC];
    A* a;
    char pad1[0x88 - 0x10];
    B* b;
};

struct Object {
    char pad[0xD8];
    Sub* sub;
};

extern "C" void fn_27_3421B0(void* unused, Object* self, s32 kind) {
    if (kind != 2) {
        Sub* sub = self->sub;
        A* a = sub->a;
        B* b = sub->b;
        float v20[3];

        v20[0] = lbl_27_rodata_7878;
        v20[1] = lbl_27_rodata_7878;
        v20[2] = lbl_27_rodata_7878;
        a->s15(v20, 0);

        b->t6(0x22, a->s4(), Vec(lbl_27_rodata_7878),
              0, -1, lbl_27_rodata_7870);
    }
}
