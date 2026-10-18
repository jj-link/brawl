#pragma force_active on
struct Dummy {
    virtual ~Dummy();
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
    virtual void v13();
    virtual void v15(int x);
};

struct Owner {
    unsigned char pad[0x204];
    Dummy* m_sub;
};

struct Arg {
    unsigned char pad[0x10];
    int m_val;
};

extern "C" void fn_14_15E8(Owner* self, Arg* arg) {
    self->m_sub->v15(arg->m_val);
}
