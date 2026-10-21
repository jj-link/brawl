#include <types.h>
#pragma force_active on

struct soBaseIface {
    virtual void v0();
    virtual void* getNode(s32 index);
    virtual void v2();
    virtual s32 getCount();
};

struct soChildIface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(u32 arg);
};

struct soOwner {
    u8 pad0[0x30];
    soBaseIface* m_iface;
    s32 m_index;
    u8 pad1[0x7d - 0x38];
    u8 m_mode;
};

extern "C" void fn_27_73FA8(soOwner* self, u32 arg) {
    if (self->m_mode == 1) {
        s32 idx = self->m_index;
        if (idx >= 0) {
            if (idx < self->m_iface->getCount()) {
                void* node = self->m_iface->getNode(idx);
                soChildIface* child = *(soChildIface**)node;
                if (child != nullptr) {
                    child->v6(arg);
                }
            }
        }
    }
}
