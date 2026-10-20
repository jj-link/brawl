#pragma force_active on
struct Obj1 {
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
    virtual void v15(unsigned int a, unsigned int b, unsigned int c);
};

struct Obj2 {
    virtual void v0();
    virtual void v3(void* p);
};

struct Mid {
    char pad[0x24];
    Obj1* m_obj1;
};

struct Arg {
    char pad[0xd8];
    Mid* m_mid;
};

struct Self {
    unsigned int m_pad;
    Obj2* m_obj2;
};

extern "C" void fn_27_16A660(Self* self, Arg* arg) {
    arg->m_mid->m_obj1->v15(0, 1, 0);
    self->m_obj2->v3(arg);
}
