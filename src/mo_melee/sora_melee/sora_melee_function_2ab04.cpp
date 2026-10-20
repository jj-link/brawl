#include <types.h>
#pragma force_active on

extern "C" void fn_27_302CC(void* r3val, void* obj, u32 a, u32 b, u32 c);

class soSubObj {
public:
    virtual void f0();
    virtual void* f1(u32 d);
    virtual void f2();
    virtual void f3();
};

class soOwner {
public:
    u8 pad0[0x28];
    soSubObj* m_28;
    u8 pad1[0x54 - 0x2C];
    void* m_54;
};

extern "C" {
void fn_27_2AB04(soOwner* self, u32 a, u32 b, u32 c, u32 d) {
    void* p = self->m_28->f1(d);
    fn_27_302CC(p, self->m_54, a, b, c);
}
}
