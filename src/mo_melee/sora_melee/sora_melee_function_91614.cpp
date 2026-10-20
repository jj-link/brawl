#pragma force_active on
class fn_27_Inner {
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

class fn_27_Outer {
public:
    char pad[0x10];
    fn_27_Inner* m_inner;
};

extern "C" {
void fn_27_91614(fn_27_Outer* self) {
    return self->m_inner->vf8();
}
}
