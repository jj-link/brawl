#pragma force_active on
class soAbstractBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual bool vf3() = 0;
};

extern "C" {
bool fn_27_1D2D0(soAbstractBase* p) {
    return !p->vf3();
}
}
