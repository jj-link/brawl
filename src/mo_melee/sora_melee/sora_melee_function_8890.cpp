#pragma force_active on
struct Base {
    unsigned char pad[8];
};

struct Model : Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void start();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void finish();

    unsigned char padC[0xB6];
    unsigned char active;
    unsigned char padC3[2];
    unsigned char flags;
};

extern "C" void begin__17soModelModuleImplFb(Model* self, bool begin) {
    if (begin == true) {
        self->active = 1;
        self->flags &= ~0x40;
        self->start();
    } else {
        self->finish();
    }
}
