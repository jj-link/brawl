#include <types.h>
#pragma force_active on

extern "C" void fn_27_302CC(void* src, void* obj, float* outX, float* outY, float* outZ);
extern "C" void fn_27_302A8(float a, float b, float c);

class SubObj {
public:
    virtual void f0();
    virtual void* f1(void* param);
};

class Owner {
public:
    u8 pad0[0x28];
    SubObj* m_28;
    u8 pad1[0x28];
    void* m_54;
};

extern "C" void fn_27_2A95C(Owner* self, void* param2, float f) {
    float x, y, z;
    void* p = self->m_28->f1(param2);
    fn_27_302CC(p, self->m_54, &x, &y, &z);
    self->m_28->f1(param2);
    fn_27_302A8(x, f, z);
}
