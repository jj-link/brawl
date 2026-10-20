#pragma force_active on
class soVirtualBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

extern "C" {
void fn_27_68A80(soVirtualBase* p) {
    p->vf4();
}
}
