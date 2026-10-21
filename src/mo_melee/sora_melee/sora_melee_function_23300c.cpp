#include <types.h>
#pragma force_active on

struct Entry {
    Entry* next;
    u8 _pad04[8];
    s32 id;
    u8 state;
    u8 _pad11[0x1B];
    u8 value;
    u8 _pad2D[2];
    u8 flag;
};

struct Self {
    u8 _pad00[0x40];
    Entry* entries;
};

extern "C" {
void* fn_80158BE0();
s32 fn_80159074(void*, s32);
s32 fn_801590F0(void*, s32);

void fn_27_23300C(Self* self) {
    Entry* entry = self->entries;

    while (entry != 0) {
        if (entry->state == 1) {
            if (fn_80159074(fn_80158BE0(), entry->id) != 0) {
                if (entry->flag == 0) {
                    entry->value = 1;
                }
                *(s32*)((u8*)entry + 0x14) = 2;
            }
        } else if (entry->state == 2) {
            if (fn_801590F0(fn_80158BE0(), entry->id) != 0) {
                if (entry->flag == 0) {
                    entry->value = 1;
                }
                *(s32*)((u8*)entry + 0x14) = 2;
            }
        }
        entry = entry->next;
    }
}
}
