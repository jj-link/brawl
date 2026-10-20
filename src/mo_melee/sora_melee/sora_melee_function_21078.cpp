#pragma force_active on
struct soInner {
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
};

struct soOuter {
    int m_pad0;
    soInner* m_inner;
    unsigned int m_8;
    unsigned int m_c;
};

extern "C" void fn_27_21078(soOuter* self) {
    if (self->m_inner) {
        self->m_inner->vf8();
    }
    self->m_8 = 0;
    self->m_c = 0;
}
