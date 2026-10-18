#pragma force_active on
class soInnerBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf10(short arg);
};

class soOuter {
public:
    int m_0;
    int m_4;
    soInnerBase* m_inner;
};

extern "C" {
void fn_27_DA004(soOuter* self, short arg) {
    self->m_inner->vf10(arg);
}
}
