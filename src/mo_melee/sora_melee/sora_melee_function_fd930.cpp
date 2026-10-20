#pragma force_active on
class fn_27_Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

class fn_27_Outer {
public:
    unsigned char pad[0x10];
    fn_27_Base m_base;
};

extern "C" void fn_27_FD930(fn_27_Outer* p) {
    p->m_base.vf1();
}
