#include <types.h>
#include <gf/gf_rumble.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Node {
    Node* next;
    u32 id;
    char pad[0x14];
    u32 key;
};
struct RumbleData {
    char pad0[0xE8];
    Node* free;
    char padEC[4];
    u32* pool0;
    u32* pool1;
};
struct RumbleSlot {
    u16 count;
    u16 pad;
    Node* head;
    u32 pad2;
};

static inline void removeId(u32 key, u32 id, RumbleData* self, RumbleSlot* slot) {
    BOOL enabled = OSDisableInterrupts();
    Node* cur = slot->head;
    while (cur != 0) {
        Node* next = cur->next;
        if (cur->id == id) {
            if (key != 0) {
                if (cur->key == key) {
                    Node** link = &slot->head;
                    while (*link != cur) {
                        link = &(*link)->next;
                    }
                    *link = next;
                    slot->count = slot->count - 1;
                    cur->next = self->free;
                    self->free = cur;
                }
            } else {
                Node** link = &slot->head;
                while (*link != cur) {
                    link = &(*link)->next;
                }
                *link = next;
                slot->count = slot->count - 1;
                cur->next = self->free;
                self->free = cur;
            }
        }
        cur = next;
    }
    OSRestoreInterrupts(enabled);
}

void gfRumble::HSD_PadRumbleRemoveId(s32 arg0, s32 arg1, s32 arg2) {
    u32 key = 0;
    RumbleData* self = (RumbleData*)this;
    RumbleSlot* slot = (RumbleSlot*)((char*)this + 0x88) + arg0;
    if (arg2 != -1) {
        if (arg0 < 4) {
            key = self->pool0[arg2 * 2];
        } else {
            key = self->pool1[arg2 * 2];
        }
    }
    removeId(key, arg1, self, slot);
}
