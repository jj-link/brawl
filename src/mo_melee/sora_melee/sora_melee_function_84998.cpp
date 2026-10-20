#pragma force_active on
class soBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" {
void fn_27_84998(soBase* p) {
    return p->vf1();
}
}
