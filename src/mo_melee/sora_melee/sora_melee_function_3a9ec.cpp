#include <types.h>
#pragma force_active on

class fn27Iface {
public:
    virtual void vf0();
    virtual void* vf1();
};

extern "C" void fn_27_3A9EC(u8* self, u32 unused, u32 value, u32 flag) {
    if (flag == 1) {
        fn27Iface* obj = *(fn27Iface**)(self + 0x34);
        u8* p = (u8*)obj->vf1();
        *(u32*)(p + 0x18) = value;
    } else {
        fn27Iface* obj = *(fn27Iface**)(self + 0x30);
        u8* p = (u8*)obj->vf1();
        *(u32*)(p + 0x1C) = value;
    }
}
