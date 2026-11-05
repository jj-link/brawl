#include <types.h>
#pragma force_active on

struct ContainerIface {
    virtual void v0();
    virtual void* getNode(s32 index);
    virtual void v2();
    virtual s32 getCount();
};

struct ItemIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(u32 arg);
};

struct Owner {
    u8 pad0[0x30];
    ContainerIface* m_iface;
    s32 m_index;
    u8 pad1[0x7d - 0x38];
    u8 m_mode;
};

extern "C" void fn_27_73E50(Owner* self, u32 arg) {
    if (self->m_mode == 1) {
        s32 idx = self->m_index;
        if (idx >= 0) {
            if (idx < self->m_iface->getCount()) {
                void* node = self->m_iface->getNode(idx);
                ItemIface* child = *(ItemIface**)node;
                if (child != nullptr) {
                    child->v4(arg);
                }
            }
        }
    }
}