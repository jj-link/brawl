#pragma force_active on
class fn_27_Sub {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class fn_27_Outer {
public:
    char pad[0xc];
    fn_27_Sub sub;
};

extern "C" void fn_27_1A8BCC(fn_27_Outer* self) {
    self->sub.vf4();
}
