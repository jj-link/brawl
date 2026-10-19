#pragma force_active on
class soWorkBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
    virtual void v4();
    virtual void v5();
};

extern "C" bool fn_27_74E68(soWorkBase* self) {
    return !self->v3();
}
