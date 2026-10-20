#pragma force_active on
extern "C" int fn_27_C81F4(void* self, int flag);

class soBaseWork {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
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

extern "C" {
void* fn_27_C7B78(soBaseWork* self, int flag) {
    int idx = fn_27_C81F4(self, flag);
    unsigned int ret = self->vf6();
    if (ret != 1 && idx >= 0) {
        self->vf15();
    }
    return (char*)self + idx * 0x14 + 0xc;
}
}
