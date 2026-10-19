#pragma force_active on
class StPlanktonBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
};

extern "C" bool fn_74_A4A8(StPlanktonBase* self) {
    return !self->vfunc3();
}
