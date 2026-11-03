#include <types.h>
#include <nt/nt_send.h>
#pragma force_active on

extern NtSend* lbl_805A03D4;

struct SendEntry {
    char pad[8];
    s32 size;
    char pad2[4];
    void* data;
};

struct SendFlag {
    s8 active;
    u8 priority;
    char pad[30];
};

struct Object {
    char pad[0x58];
    SendEntry entries[4];
    char pad2[8];
    SendFlag flags[4];
};

extern "C" void fn_80142A80(Object* self) {
    u8 done[4];
    done[0] = self->flags[0].active == 0;
    done[1] = self->flags[1].active == 0;
    done[2] = self->flags[2].active == 0;
    done[3] = self->flags[3].active == 0;

    for (;;) {
        SendFlag* flag;
        SendEntry* entry;
        entry = self->entries;
        flag = self->flags;
        u8 best = 0;
        int selected = -1;

        for (u8 i = 0; i < 4; i++, entry++, flag++) {
            if (!done[i] && flag->active && entry->size != 0 &&
                best <= flag->priority) {
                best = flag->priority;
                selected = i;
            }
        }

        if (selected >= 0) {
            done[selected] = true;
            SendEntry* chosen = &self->entries[selected];
            lbl_805A03D4->pushback(selected, chosen->data, chosen->size);
            chosen->size = 0;
        }

        if (selected < 0)
            break;
    }
}
