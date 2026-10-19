#pragma force_active on
class soVirtualBase {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual bool vf4() = 0;
};

extern "C" bool fn_27_85108(soVirtualBase* p) {
    return !p->vf4();
}
