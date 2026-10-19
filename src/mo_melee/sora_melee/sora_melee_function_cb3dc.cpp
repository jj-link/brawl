#pragma force_active on
class soGeneralWorkBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" {
bool fn_27_CB3DC(soGeneralWorkBase* p) {
    return !p->vfunc3();
}
}
