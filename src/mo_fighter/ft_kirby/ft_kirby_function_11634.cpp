#pragma force_active on
struct ftKirbyBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual bool vf3();
    virtual void vf4();
    virtual void vf5();
};

extern "C" bool fn_96_11634(ftKirbyBase* self) {
    return !self->vf3();
}
