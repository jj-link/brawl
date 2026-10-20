#pragma force_active on
class soSub {
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

class soOuter {
public:
    int m_0[4];
    soSub m_sub;
};

extern "C" {
void fn_27_F2618(soOuter* self) {
    self->m_sub.vf8();
}
}
