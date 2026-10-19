#pragma force_active on
class soBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_27_CD5AC(soBase* self) {
    return !self->vf3();
}
