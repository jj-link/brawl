#include <types.h>
#pragma force_active on
struct D { u32 w0,w1,w2,w3; u8 b; };
struct I { virtual void v0(); virtual D* get(u32 idx); };
struct O { u8 pad[0x40]; I* m; };
extern "C" void fn_27_B9810(const O* self, D* out, u32 idx) {
    I* ifc = self->m;
    D* d = ifc->get(idx);
    out->w0 = d->w0; out->w1 = d->w1; out->w2 = d->w2; out->w3 = d->w3; out->b = d->b;
}
