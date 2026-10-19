#pragma force_active on
class fnBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
    virtual void vf4();
    virtual void vf5();
};

extern "C" bool fn_27_123C4C(fnBase* p) {
    return !p->vf3();
}
