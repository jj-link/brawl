#pragma force_active on

extern "C" const float lbl_27_rodata_7C14;
extern "C" const float lbl_27_rodata_7C0C;

struct Obj58 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(unsigned int);
    virtual unsigned int v8();
};

struct Obj88 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(unsigned int, unsigned int, float*, float*, float*, float*,
                    unsigned int, unsigned int, float);
};

struct Inner {
    unsigned char pad1[0x58];
    Obj58* obj58;
    unsigned char pad2[0x2C];
    Obj88* obj88;
};

struct Mid {
    unsigned char pad[0xD8];
    Inner* inner;
};

struct Outer {
    unsigned char pad[0x60];
    Mid* mid;
};

extern "C" void fn_27_38068C(Outer* self, unsigned int arg) {
    Mid* mid = self->mid;
    unsigned int result = mid->inner->obj58->v8();

    if (result != arg) {
        mid->inner->obj58->v7(arg);

        unsigned int id = 0x0104004E;
        float value = lbl_27_rodata_7C14;
        float values[12];

        values[0] = value;
        values[1] = value;
        values[2] = value;
        values[3] = value;
        values[4] = value;
        values[5] = value;
        values[6] = value;
        values[7] = value;
        values[8] = value;
        values[9] = value;
        values[10] = value;
        values[11] = value;

        mid->inner->obj88->v8(id, 0, &values[9], &values[6],
                              &values[3], &values[0], 0, 0,
                              lbl_27_rodata_7C0C);
    }
}
