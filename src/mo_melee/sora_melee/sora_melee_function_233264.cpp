#include <types.h>
#pragma force_active on

struct Sub {
    u8 pad[0x7c];
    u16 kind;
};

struct Entry {
    u8 pad[0x90];
    Sub* sub;
};

struct Manager {
    u8 pad[0x4c];
    Entry** entries;
    u32 size;
};

extern "C" {
void* fn_40_138F0(Entry* entry, u32 kind, s32 r5, s32 count);

void* fn_27_233264(Manager* mgr, u32 kind, s32 r5, s32 count) {
    for (u32 i = 0; i < mgr->size; i++) {
        Entry* e = mgr->entries[i];
        if (kind == e->sub->kind) {
            if (count == 0) {
                return fn_40_138F0(mgr->entries[i], kind, r5, count);
            }
            count--;
        }
    }
    return 0;
}
}
