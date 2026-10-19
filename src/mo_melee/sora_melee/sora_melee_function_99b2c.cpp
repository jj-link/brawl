#pragma force_active on
typedef unsigned char u8;

struct Inner {
    virtual void v0();
    virtual Inner* v1();
    virtual void v2();
    virtual void v3();
    u8 pad[0x24];
    u8 m_28;
};

struct Outer {
    u8 pad[0x4c];
    Inner* m_4c;
};

extern "C" void fn_27_99B2C(Outer* self) {
    Inner* p = self->m_4c->v1();
    p->m_28 = 0;
}
