#pragma force_active on
class soBase {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5();
};

extern "C" bool fn_27_1F00C(soBase* p) {
    return !p->vf5();
}
