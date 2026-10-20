#pragma force_active on
class soBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_86C08(soBase* p) {
    return !p->vf3();
}
