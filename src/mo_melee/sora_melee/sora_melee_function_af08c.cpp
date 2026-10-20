#pragma force_active on
class soEmbedded {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
};

class soOuter {
public:
    char pad[0x10c];
    soEmbedded m_embedded;
};

extern "C" {
void fn_27_AF08C(soOuter* self) {
    self->m_embedded.vf10();
}
}
