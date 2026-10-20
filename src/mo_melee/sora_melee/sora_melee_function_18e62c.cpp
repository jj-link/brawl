#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual u32 get(u32 flag) = 0;
    virtual void set(u32 value, u32 flag) = 0;
};

class Mid {
public:
    char pad[0x64];
    Inner* inner;
};

class Outer {
public:
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_27_18E62C(void* unused, Outer* obj) {
    u32 v = obj->mid->inner->get(0x20000000);
    obj->mid->inner->set(v + 1, 0x20000000);
}
}
