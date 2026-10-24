#pragma force_active on
#pragma fp_contract on

struct B0 {
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
    virtual void v12(float *f, float *out);
    char pad[0x8];
    float d;
};

extern "C" float fn_802D0890(B0 *a0, float *f) {
    __attribute__((aligned(16))) float v[3];
    a0->v12(f, v);
    float t = v[0] * f[0] + v[1] * f[1] + v[2] * f[2];
    return a0->d + t;
}
