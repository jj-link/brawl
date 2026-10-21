#pragma force_active on
class fnBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

extern "C" {
void fn_801CF61C(fnBase* p) {
    p->vf2();
}
}
