#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_80487A38[];
void fn_802D95E4(void* self, void* v);

void* fn_802DABE8(void* p) {
    u8* self = (u8*)p;
    void* saved = *(void**)(self + 0x14);
    *(s16*)(self + 6) = 1;
    *(void**)self = (void*)lbl_80487A38;
    fn_802D95E4(self + 0xC, saved);
    fn_802D95E4(self + 0xC, self);
    return p;
}
}
