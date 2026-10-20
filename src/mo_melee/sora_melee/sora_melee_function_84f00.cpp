#pragma force_active on
class soTargetAbstract {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf4();
};

extern "C" {
bool fn_27_84F00(soTargetAbstract* p) {
    return !p->vf4();
}
}
