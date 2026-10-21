#include <types.h>
#pragma force_active on

struct Inner {
    virtual void* vf0();
    virtual void* vf3(void* p);
};

struct Outer {
    u8 pad[0x28];
    Inner* m_28;
    u8 pad2[0x54 - 0x2C];
    void* m_54;
};

extern "C" void fn_27_302CC(void* src, void* obj, float* a, float* b, float* c);
extern "C" void fn_27_302A8(float a, float b, float c);

extern "C" void fn_27_2A8C4(Outer* self, void* p, float f) {
    float x;
    float y;
    float z;
    void* s = self->m_28->vf3(p);
    fn_27_302CC(s, self->m_54, &x, &y, &z);
    self->m_28->vf3(p);
    fn_27_302A8(f, y, z);
}
