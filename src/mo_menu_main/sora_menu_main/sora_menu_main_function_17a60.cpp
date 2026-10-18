#pragma force_active on
class Sub {
public:
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
    virtual void target(void* arg);
};

struct Mid {
    unsigned char _00[0x10];
    void* m_p;
};

struct Outer {
    unsigned char _000[0x650];
    Mid* m_mid;
    Sub* m_sub;
};

extern "C" {
void fn_2_17A60(Outer* self) {
    self->m_sub->target(self->m_mid->m_p);
}
}
