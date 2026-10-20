#pragma force_active on
class soInnerObj {
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
};

class soOuterObj {
public:
    char m_pad[0x10];
    soInnerObj m_inner;
};

extern "C" {
void fn_27_1C8098(soOuterObj* self) {
    self->m_inner.vf8();
}
}
