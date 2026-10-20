#pragma force_active on
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
};

struct Holder {
    char pad[0x2c];
    Target* m_target;
};

extern "C" {
int fn_41_2B3E4(Holder* self) {
    return self->m_target->v5();
}
}
