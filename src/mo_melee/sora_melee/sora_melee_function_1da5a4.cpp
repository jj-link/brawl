#include <types.h>
#pragma force_active on

class fn27Iface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u32 a, u32 b);
};

extern "C" {
void fn_27_1DA5A4(u8* self, u32 a) {
    u8* p = *(u8**)(self + 0x60);
    fn27Iface* o = *(fn27Iface**)(*(u8**)(p + 0xD8) + 0x14);
    o->vf6(a, 0);
}
}
