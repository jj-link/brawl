#pragma force_active on

extern "C" {

struct V3 { float x, y, z; };

class Obj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual float m18();
};

struct R31 {
    char pad0[4];
    float f4;
    char pad1[0x14];
    float f1c;
    char pad2[8];
    float f28;
};

void* fn_41_159AC(void*, int);
void fn_41_6270(V3*, int, int, float);
double fn_8040036C(double);
extern const float lbl_41_rodata_BE0;

void fn_41_11320(void*, int arg1, void* arg2, Obj* arg3, int arg4, int arg5, int* arg6) {
    V3 v1, v2;
    R31* p = (R31*)fn_41_159AC(arg2, 9);
    if (p != 0) {
        fn_41_6270(&v1, arg1, arg4, arg3->m18());
        fn_41_6270(&v2, arg1, arg4, -arg3->m18());
        float f31 = v2.y - v1.y;
        float f30 = lbl_41_rodata_BE0;
        if (arg5 > 0 && f30 != f31) {
            f30 = f31 / (float)arg5;
            float tmp = f31 / f30;
            *arg6 = (int)(float)fn_8040036C((double)tmp);
        }
        p->f28 = f31;
        p->f4 = f30;
        p->f1c = f30;
    }
}

}