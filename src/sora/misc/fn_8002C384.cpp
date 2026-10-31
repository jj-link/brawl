#include <types.h>
#include <revolution/OS/OSInterrupt.h>

#pragma force_active on

struct RumbleNode {
    RumbleNode* next;
    char pad0[4];
    u8 mask;
};

struct gfRumble {
    char pad0[0xE8];
    RumbleNode* unkE8;
    void HSD_PadRumbleRemoveMask(s32, u32);
};

void gfRumble::HSD_PadRumbleRemoveMask(s32 pad, u32 mask) {
    char* slot = (char*)this + pad * 12;
    BOOL enabled = OSDisableInterrupts();
    RumbleNode* next;
    RumbleNode* cur = *(RumbleNode**)(slot + 0x8C);

    while (cur != 0) {
        next = cur->next;

        if (cur->mask & mask) {
            RumbleNode** link = (RumbleNode**)(slot + 0x8C);

            while (*link != cur) {
                link = &(*link)->next;
            }

            *link = next;
            *(u16*)(slot + 0x88) = *(u16*)(slot + 0x88) - 1;
            cur->next = unkE8;
            unkE8 = cur;
        }

        cur = next;
    }

    OSRestoreInterrupts(enabled);
}
