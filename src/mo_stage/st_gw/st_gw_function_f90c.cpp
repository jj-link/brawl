#pragma force_active on
class ftBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf5();
};

extern "C" bool fn_63_F90C(ftBase* self) {
    return !self->vf5();
}
