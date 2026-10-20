#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void vf0();
    virtual void* vf1();
};

class soOwner {
public:
    char pad[0x30];
    soVirtBase* m_base;
};

extern "C" void fn_27_A765C(void* obj, u32 a, u32 b);

extern "C" void fn_27_A4688(soOwner* self, u32, u32 a, u32 b) {
    fn_27_A765C(self->m_base->vf1(), a, b);
}
