#pragma force_active on
struct fn27Inner {
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

struct fn27Outer {
    int m_00[4];
    fn27Inner m_10;
};

extern "C" void fn_27_1E6A3C(fn27Outer* p) {
    p->m_10.vf8();
}
