#pragma force_active on
class soVirtualBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_27_84A30(soVirtualBase* p) {
    p->vf1();
}
