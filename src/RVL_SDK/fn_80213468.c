#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct IPCHeapChunk {
    u32 magic;                 // at 0x0
    u32 size;                  // at 0x4
    struct IPCHeapChunk* prev; // at 0x8
    struct IPCHeapChunk* next; // at 0xC
} IPCHeapChunk;

typedef struct IPCHeapDesc {
    void* start;        // at 0x0
    u32 WORD_0x4;       // at 0x4
    u32 size;           // at 0x8
    IPCHeapChunk* head; // at 0xC
} IPCHeapDesc;

extern IPCHeapDesc lbl_804F65E0[8];

s32 fn_80213468(void* base, u32 size)
{
    s32 i;
    s32 result = -4;
    BOOL enabled = OSDisableInterrupts();
    IPCHeapDesc* desc;

    if ((u32)base % 32 != 0) {
        goto _exit;
    }

    for (i = 0; i < 8; i++) {
        if (lbl_804F65E0[i].start == NULL) {
            break;
        }
    }

    if (i == 8) {
        result = -5;
        goto _exit;
    }

    desc = &lbl_804F65E0[i];
    desc->start = base;
    desc->size = size;
    desc->head = (IPCHeapChunk*)base;

    desc->head->magic = 0xBABE0000;
    desc->head->size = size - sizeof(IPCHeapChunk);
    desc->head->prev = NULL;
    desc->head->next = NULL;

    result = i;
_exit:
    OSRestoreInterrupts(enabled);
    return result;
}
