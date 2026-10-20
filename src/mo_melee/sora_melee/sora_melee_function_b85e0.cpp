#include <types.h>
#pragma force_active on

struct fn_27_Data {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u8 b;
};

struct fn_27_Ifc {
    virtual void v0();
    virtual fn_27_Data* get(u32 idx);
};

struct fn_27_Owner {
    u8 pad[0x38];
    fn_27_Ifc* m_ifc;
};

extern "C" {
void fn_27_B85E0(const fn_27_Owner* self, fn_27_Data* out, u32 idx) {
    fn_27_Ifc* ifc = self->m_ifc;
    fn_27_Data* d = ifc->get(idx);
    out->w0 = d->w0;
    out->w1 = d->w1;
    out->w2 = d->w2;
    out->w3 = d->w3;
    out->b = d->b;
}
}
