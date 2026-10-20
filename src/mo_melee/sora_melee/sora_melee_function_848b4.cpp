#pragma force_active on
class fnVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_27_848B4(fnVirtBase* p) {
    p->vf1();
}
