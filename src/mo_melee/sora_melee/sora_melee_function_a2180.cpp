#include <types.h>
#pragma force_active on

class soVirtPad {
public:
    u32 a;
    u32 b;
};

class soVirtIface : public soVirtPad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void call(u32 unused, u32 id);
};

class soVirtOwner {
public:
    u32 pad[7];
    soVirtIface* m_items[16];
};

extern "C" {
void fn_27_A2180(soVirtOwner* self, u32 unused, u32 id) {
    self->m_items[id >> 28]->call(unused, id & 0xFFFFFF);
}
}
