#include <types.h>
#pragma force_active on

struct Obj {
    char pad[0xC];
    float m_f0c;
};

struct Iface {
    virtual void v0();
    virtual Obj* get(int index);
    virtual void v2();
    virtual int size();
};

struct Holder {
    char pad[0x40];
    Iface* m_iface;
};

extern "C" float lbl_27_rodata_82C;

extern "C" int fn_27_5ED5C(Holder* self) {
    int count = self->m_iface->size();
    float zero = lbl_27_rodata_82C;
    for (int i = 0; i < count; i++) {
        if (self->m_iface->get(i)->m_f0c > zero) {
            return 1;
        }
    }
    return 0;
}
