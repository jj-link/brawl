#pragma force_active on
class soFnBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf5();
};

extern "C" {
bool fn_27_84C90(soFnBase* p) {
    return !p->vf5();
}
}
