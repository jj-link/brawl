#pragma force_active on
class scBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual unsigned int vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
};

extern "C" int fn_27_C8F28(void*);

extern "C" void* fn_27_C888C(scBase* self) {
    int idx = fn_27_C8F28(self);
    if (self->vf4() != 1 && idx >= 0) {
        self->vf13();
    }
    return (char*)self + idx * 0x18 + 0xc;
}
