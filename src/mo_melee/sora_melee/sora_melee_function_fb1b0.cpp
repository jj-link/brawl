#pragma force_active on
struct fn27Obj {
    virtual void vf0();
    virtual fn27Obj* vf1(void* p);
};

extern "C" void fn_27_FB1B0(fn27Obj* self, unsigned int* other, void* arg) {
    self = self->vf1(arg);
    *(unsigned int*)self = *other;
}
