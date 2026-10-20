#pragma force_active on
class soVirtualBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_27_4D77C(soVirtualBase* p) {
    return !p->vf3();
}
}
