#include <types.h>
#pragma force_active on

struct fnTarget {
    char pad0[0x4c];
    float a;
    char pad1[4];
    float b;
    char pad2[0x74 - 0x58];
    u8 c;
};

class fnIface {
public:
    virtual void v0();
    virtual fnTarget* get(int idx);
};

struct fnOwner {
    char pad[8];
    fnIface* m_iface;
};

extern "C" {
void fn_27_378D0(fnOwner* self, int idx, float f1, float f2, u8 flag) {
    fnTarget* t = self->m_iface->get(idx);
    t->a = f1;
    t->b = f2;
    t = self->m_iface->get(idx);
    t->c = flag;
}
}
