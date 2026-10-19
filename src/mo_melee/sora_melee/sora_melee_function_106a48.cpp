#pragma force_active on
class fn_27_106A48Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" {
bool fn_27_106A48(fn_27_106A48Base* p) {
    return !p->vf3();
}
}
