#include <types.h>
#pragma force_active on

class soIface {
public:
    virtual void* vf0();
    virtual void* vf1(u32 b, float f1, float f2, float f3);
};

struct Owner {
    u8 pad[0x28];
    soIface* iface;
};

extern "C" void fn_27_302B8(void* p, u32 a, float f1, float f2, float f3);

extern "C" void fn_27_2AA8C(Owner* self, u32 a, u32 b, float f1, float f2, float f3) {
    void* r = self->iface->vf1(b, f1, f2, f3);
    fn_27_302B8(r, a, f1, f2, f3);
}
