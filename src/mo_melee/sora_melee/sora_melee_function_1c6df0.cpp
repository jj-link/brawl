#pragma force_active on
struct fn_27_Base {
    virtual void vf0();
    virtual fn_27_Base* vf1(void* p);
    virtual void vf2();
    virtual void vf3();
};

extern "C" {
void fn_27_1C6DF0(fn_27_Base* self, void** src, void* arg) {
    fn_27_Base* ret = self->vf1(arg);
    *(void**)ret = *src;
}
}
