#pragma force_active on
struct Obj {
    virtual void vf0();
    virtual void vf1(int, int, int);
};

extern "C" void fn_801AC9E0();

extern "C" void fn_801ACB68(Obj* self) {
    fn_801AC9E0();
    self->vf1(1, 0, 0);
}
