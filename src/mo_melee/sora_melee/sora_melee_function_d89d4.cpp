#pragma force_active on
class soSubObj {
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
    soSubObj m_sub;
};

extern "C" void fn_27_D89D4(soOuterObj* self) {
    self->m_sub.vf8();
}
