#pragma force_active on
class soWorkBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" {
bool fn_27_106978(soWorkBase* p) {
    return !p->vf3();
}
}
