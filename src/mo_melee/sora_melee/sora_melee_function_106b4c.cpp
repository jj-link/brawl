#pragma force_active on
struct fn_27_106B4CBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_27_106B4C(fn_27_106B4CBase* p) {
    return !p->vf3();
}
}
