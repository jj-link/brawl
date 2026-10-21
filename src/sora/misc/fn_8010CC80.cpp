#pragma force_active on
struct Inner {
    unsigned char pad[0x10];
    void* f10;
};

struct Iface {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void call(void* arg);
};

struct Obj {
    unsigned char pad[0x10c];
    Inner* f10c;
    unsigned char pad2[0x160 - 0x110];
    Iface* f160;
};

extern "C" void fn_8010CC80(Obj* self) {
    self->f160->call(self->f10c->f10);
}
