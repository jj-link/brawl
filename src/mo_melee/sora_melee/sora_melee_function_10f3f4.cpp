#pragma force_active on
class soWorkBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf4();
};

extern "C" {
bool fn_27_10F3F4(soWorkBase* p) {
    return !p->vf4();
}
}
