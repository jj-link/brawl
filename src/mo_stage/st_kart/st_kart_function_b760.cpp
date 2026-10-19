#pragma force_active on
struct fn_49_B760_Base {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
};

extern "C" bool fn_49_B760(fn_49_B760_Base* self) {
    return self->vf3() == 0;
}
