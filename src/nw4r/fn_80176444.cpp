#include <types.h>
#pragma force_active on

extern "C" void fn_801747D8(void* self);
extern "C" u8 lbl_804654A8[];

extern "C" void* fn_80176444(void* p) {
    fn_801747D8(p);
    *(void**)p = lbl_804654A8;
    return p;
}
