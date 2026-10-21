#pragma force_active on
class fnBase {
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
};

extern "C" {
void fn_802D95D0(fnBase* p) {
    p->vf7();
}
}
