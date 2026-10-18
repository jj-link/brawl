#pragma force_active on
struct Inner {
    virtual void vf0();
    virtual Inner* vf1();
    int pad[4];
    float m_14;
};

struct Outer {
    char pad[0x30];
    Inner* m_inner;
};

extern "C" void fn_27_3A6D8(Outer* self, float value) {
    self->m_inner->vf1()->m_14 = value;
}
