#pragma force_active on

class Sub12 {
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
};

class Sub16 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int arg);
};

struct Owner {
    char pad[0xc];
    Sub12* m_c;
    Sub16* m_10;
};

extern "C" {
void fn_802A229C(Owner* self, int arg) {
    self->m_c->v8();
    if (self->m_10 != 0) {
        self->m_10->v8(arg);
    }
}
}
