#pragma force_active on
struct fn41SubObj {
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
    virtual void vf13();
};

struct fn41Owner {
    char pad[0x2c];
    fn41SubObj* m_sub;
};

extern "C" void fn_41_2B394(fn41Owner* owner) {
    owner->m_sub->vf11();
}
