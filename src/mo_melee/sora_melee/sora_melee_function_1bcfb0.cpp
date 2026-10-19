#pragma force_active on
struct stVirtBase {
    virtual void vf0();
    virtual void** vf1(void* p);
    virtual void vf2();
};

extern "C" void fn_27_1BCFB0(stVirtBase* self, void** src, void* p) {
    void** dst = self->vf1(p);
    *dst = *src;
}
