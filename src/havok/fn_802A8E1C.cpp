#include <types.h>
#pragma force_active on

extern "C" void fn_802A3A4C(void* self);
extern "C" u8 lbl_804868AC[];

extern "C" void* fn_802A8E1C(void* p) {
    fn_802A3A4C(p);
    *(void**)p = lbl_804868AC;
    return p;
}
