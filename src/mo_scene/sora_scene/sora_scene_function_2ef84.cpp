#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct Unk {
    u8 pad[0x24];
    void* unk24;
    void* unk28;
};

extern "C" void fn_1_2EF84(Unk* self) {
    if (self->unk24) {
        operator delete(self->unk24);
        self->unk24 = nullptr;
    }
    if (self->unk28) {
        operator delete(self->unk28);
        self->unk28 = nullptr;
    }
    u8* g = (u8*)g_GameGlobal;
    u8* p = (u8*)*(void**)(g + 8);
    p[0x62] &= ~0x10;
}
