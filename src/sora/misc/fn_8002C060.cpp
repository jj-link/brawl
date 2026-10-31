#include <revolution/OS/OSInterrupt.h>
#include <types.h>

#pragma force_active on

struct Node {
    Node* next;
};

struct Entry {
    u8 pad0[2];
    u8 flag;
    u8 pad1;
    u16 count;
    u8 pad2[2];
    Node* head;
};

struct Context {
    u8 pad[0x84];
    Entry entries[8];
    u8 pad2[4];
    Node* pool;
};

extern "C" void fn_8002C060(Context* ctx) {
    Entry* entry = ctx->entries;
    u8* base = (u8*)ctx;

    for (s32 i = 0; i < 8; i++) {
        BOOL enabled = OSDisableInterrupts();
        Node* node = entry->head;

        if (node == 0) {
            goto done;
        }
        goto check;

    body:
        {
            Node* next = node->next;
            Node** link = &entry->head;

            while (*link != node) {
                link = (Node**)*link;
            }

            *link = next;
            entry->count--;
            node->next = ctx->pool;
            ctx->pool = node;
            node = next;
        }

    check:
        if (node != 0) {
            goto body;
        }

    done:
        OSRestoreInterrupts(enabled);
        enabled = OSDisableInterrupts();
        base[0x86] = 1;
        OSRestoreInterrupts(enabled);

        entry++;
        base += 0xC;
    }
}
