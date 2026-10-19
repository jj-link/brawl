#pragma force_active on
struct Fn77Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int vf3();
};

extern "C" bool fn_77_5F00(Fn77Base* self) {
    return self->vf3() == 0;
}
