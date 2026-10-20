#pragma force_active on
struct Q {
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
    virtual float v10(float);
};

struct P {
    char pad[0xc];
    Q* q;
};

struct O {
    char pad[0xd8];
    P* p;
};

extern float lbl_27_rodata_7C50;

extern "C" {
float fn_27_386D78(void*, O* o) {
    return o->p->q->v10(lbl_27_rodata_7C50);
}
}
