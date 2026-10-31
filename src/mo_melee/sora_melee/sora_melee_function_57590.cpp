#pragma force_active on
struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(float f, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(float f, unsigned int a, unsigned int b);
};

struct Sub {
    char pad[0x34];
    unsigned int flags;
};

extern "C" {
    extern const float lbl_27_rodata_72C;
}

extern "C" void fn_27_57590(Base* self, Sub* s, float f) {
    unsigned int r0 = s->flags;
    unsigned int bits = (r0 >> 25) & 0x1F;
    if (bits == 0) {
        return;
    }
    if (f > lbl_27_rodata_72C) {
        self->v15(f, bits, r0 >> 30);
    } else {
        self->v7(f, 15, 0, 0, 0);
    }
}
