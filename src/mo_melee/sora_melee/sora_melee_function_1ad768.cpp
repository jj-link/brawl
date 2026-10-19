#pragma force_active on
class soGeneralWorkAbstractStub {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual bool vfunc4();
};

extern "C" {
bool fn_27_1AD768(soGeneralWorkAbstractStub* p) {
    return !p->vfunc4();
}
}
