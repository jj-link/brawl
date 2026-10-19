#pragma force_active on
typedef unsigned int u32;

struct Base {
    virtual void vf0(u32* p);
    virtual void vf1(u32* p);
    virtual void vf2(u32* p);
    virtual void vf3(u32* p);
    virtual void vf4(u32* p);
    virtual void vf5(u32* p);
    virtual void vf6(u32* p);
    virtual void vf7(u32* p);
    virtual void vf8(u32* p);
    virtual void vf9(u32* p);
    virtual void vf10(u32* p);
};

extern "C" {
void fn_113_23FA4(Base* self, u32 arg) {
    self->vf10(&arg);
}
}
