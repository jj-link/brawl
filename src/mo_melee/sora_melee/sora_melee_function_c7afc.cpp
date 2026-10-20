#pragma force_active on
extern "C" void* fn_27_C81F4(void* self);

class scWorkBase {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual unsigned int vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

extern "C" void* fn_27_C7AFC(scWorkBase* self) {
    int idx = (int)fn_27_C81F4(self);
    if (self->vf6() != 1 && idx >= 0) {
        self->vf15();
    }
    return (char*)self + idx * 20 + 12;
}
