#pragma force_active on
class fn_27_Base {
public:
    virtual void vf0();
    virtual fn_27_Base* vf1(void* a);
};

extern "C" void fn_27_1C3298(fn_27_Base* self, void** src, void* arg) {
    fn_27_Base* r = self->vf1(arg);
    *(void**)r = *src;
}
