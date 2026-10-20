#pragma force_active on
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
    virtual void v13(unsigned int arg);
};

struct Sub {
    char pad[0x40];
    Iface* iface;
};

struct Owner {
    char pad[0xd8];
    Sub* sub;
};

extern "C" void fn_27_1921F4(void* unused, Owner* owner) {
    owner->sub->iface->v13(0x109);
}
