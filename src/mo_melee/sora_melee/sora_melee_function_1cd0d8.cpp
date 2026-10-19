#pragma force_active on
struct fnBase {
    virtual void vf0();
    virtual fnBase* vf1(void* p);
    virtual void vf2();
    virtual void vf3();
};

extern "C" {
void fn_27_1CD0D8(fnBase* self, fnBase* src, void* p) {
    fnBase* r = self->vf1(p);
    *(void**)r = *(void**)src;
}
}
