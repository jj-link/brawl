#pragma force_active on
class FtBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" bool fn_96_1F870(FtBase* self) {
    return !self->vfunc3();
}
