#include <types.h>
#pragma force_active on

struct Iface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(u32 arg);
};

extern "C" {
int fn_27_298ED8(void* unused, u8* p) {
    u8* o = *(u8**)(p + 0x60);
    u8* o2 = *(u8**)(o + 0xd8);
    Iface* i = *(Iface**)(o2 + 0x64);
    return i->f4(0x10000000);
}
}
