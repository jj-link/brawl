#pragma force_active on
class soVirtBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

extern "C" {
void fn_27_8494C(soVirtBase* p) {
    p->vf1();
}
}
