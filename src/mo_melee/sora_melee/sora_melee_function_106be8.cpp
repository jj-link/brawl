#pragma force_active on
class fnBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_27_106BE8(fnBase* p) {
    return !p->vf3();
}
}
