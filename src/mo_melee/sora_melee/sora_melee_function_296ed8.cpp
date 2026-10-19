#pragma force_active on
class soBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_27_296ED8(soBase* p) {
    return !p->vf3();
}
