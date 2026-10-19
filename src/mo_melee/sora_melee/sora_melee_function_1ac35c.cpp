#pragma force_active on
class soBaseWork {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf4();
};

extern "C" bool fn_27_1AC35C(soBaseWork* self) {
    return !self->vf4();
}
