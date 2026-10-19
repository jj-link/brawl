#pragma force_active on
class stVirtBase {
public:
    virtual void vf0();
    virtual void* vf1(void* p);
};

extern "C" {
void fn_27_1AD1B0(stVirtBase* self, void** src, void* p) {
    void** dst = (void**)self->vf1(p);
    *dst = *src;
}
}
