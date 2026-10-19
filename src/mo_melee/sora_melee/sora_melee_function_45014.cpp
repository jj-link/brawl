#pragma force_active on
struct Inner {
    virtual void vf0();
    virtual Inner* vf1(unsigned int v);
    unsigned char pad[0x30];
    unsigned char m_34;
};

struct Outer {
    unsigned char pad[0x58];
    Inner* m_58;
};

extern "C" void fn_27_45014(Outer* self, unsigned char a, unsigned int b) {
    self->m_58->vf1(b)->m_34 = a;
}
