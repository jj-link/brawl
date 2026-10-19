#pragma force_active on
struct fn27Obj {
    virtual void vf0();
    virtual void* vf1(void* p);
    virtual void vf2();
    virtual void vf3();
};

extern "C" void fn_27_F58AC(fn27Obj* self, void** src, void* p) {
    void** dst = (void**)self->vf1(p);
    *dst = *src;
}
