#include <types.h>
#pragma force_active on

struct FnObjA {
    virtual void f0();
    virtual void* f1();
    virtual void f2();
    virtual void f3();
};

struct FnObjB {
    virtual void g0();
    virtual void* g1(u32 v);
    virtual void g2();
    virtual void g3();
};

struct Fn27Self {
    u8 pad0[0x28];
    FnObjA* m_28;
    u8 pad1[0x54 - 0x2C];
    void* m_54;
};

extern "C" void fn_27_302CC(void* r3val, void* obj, float* a, float* b, float* c);
extern "C" void fn_27_302A8(void* obj, float a, float b, float c);

extern "C" {
void fn_27_2A9F4(Fn27Self* self, u32 param, float value) {
    float x, y, z;
    fn_27_302CC(((FnObjA*)self->m_28)->f1(), self->m_54, &x, &y, &z);
    void* r = ((FnObjB*)self->m_28)->g1(param);
    fn_27_302A8(r, x, y, value);
}
}
