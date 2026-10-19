#pragma force_active on
typedef unsigned char u8;

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
    virtual float v9();
};

class Mid {
public:
    u8 pad[0xC];
    Sub* m_sub;
};

class Self {
public:
    u8 pad[0x1B4];
    Mid* m_mid;
};

class Arg {
public:
    u8 pad[0x8];
    float m_f;
};

extern "C" bool fn_41_5730(Self* self, Arg* arg) {
    float v = self->m_mid->m_sub->v9();
    return arg->m_f == v;
}
