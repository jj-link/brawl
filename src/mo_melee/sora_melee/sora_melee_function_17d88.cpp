#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_202BC(void* p);

struct Inner {
    u8 pad[0x24];
    u8 flags;
};

class Outer {
public:
    virtual void vf0();
    virtual Inner* vf1(u32 arg);
    virtual void vf2();
    virtual void vf3();
};

struct Host {
    u8 pad[0x90];
    Outer* m_outer;
};

extern "C" u32 fn_27_17D88(Host* self, u32 arg) {
    Inner* p = self->m_outer->vf1(arg);
    if (((p->flags >> 5) & 1) == 0) {
        return fn_27_202BC(self->m_outer->vf1(arg));
    }
    return 0;
}
