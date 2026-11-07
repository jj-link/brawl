#pragma force_active on
#pragma fp_contract on

extern const float lbl_805A40B0;

struct Inner {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void f14();
};

struct A {
    char pad[0x14];
    Inner *p;
    char pad2[0x8];
    float x, y, z;
};

extern "C" void fn_802D0BE4(A *a, float *m, float *o) {
    __attribute__((aligned(16))) float v[4];
    a->p->f14();
    float x = a->x, y = a->y, z = a->z;
    v[0] = z * m[8] + (x * m[0] + y * m[4]);
    v[1] = z * m[9] + (x * m[1] + y * m[5]);
    v[2] = z * m[10] + (x * m[2] + y * m[6]);
    v[3] = lbl_805A40B0;
    o[0] += v[0]; o[1] += v[1]; o[2] += v[2]; o[3] += v[3];
    o[4] += v[0]; o[5] += v[1]; o[6] += v[2]; o[7] += v[3];
}