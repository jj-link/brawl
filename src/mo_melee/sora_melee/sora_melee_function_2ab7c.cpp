#include <types.h>
#pragma force_active on

struct Fn27Src;

struct Fn27Iface {
    virtual void v0();
    virtual Fn27Src* v1(u32 p);
};

struct Fn27Self {
    u8 pad0[0x28];
    Fn27Iface* iface;
    u8 pad1[0x54 - 0x2C];
    void* unk54;
};

extern "C" void fn_27_302E8(const Fn27Src* src, void* unused, float* outA, float* outB, float* outC, u32* outD);

extern "C" void fn_27_2AB7C(Fn27Self* self, float* p2, float* p3, float* p4, u32* p5, u32 p6) {
    Fn27Src* src = self->iface->v1(p6);
    fn_27_302E8(src, self->unk54, p2, p3, p4, p5);
}
