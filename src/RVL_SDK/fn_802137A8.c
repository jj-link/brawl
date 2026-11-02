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

s32 fn_802137A8(s32 handle, void* arg1)
{
    IPCHeapChunk* next;
    IPCHeapDesc* desc;
    IPCHeapChunk* chunk;
    IPCHeapChunk* it;
    u8* block = (u8*)arg1;
    s32 result = -4;
    BOOL enabled = OSDisableInterrupts();

    if (block != NULL) {
        if (handle < 0 || handle >= 8 ||
            (desc = &lbl_804F65E0[handle], desc->start == NULL)) {
            result = -4;
        } else if ((u32)block >= (u32)desc->start + sizeof(IPCHeapChunk) &&
                   (u32)block <= (u32)desc->start + desc->size) {
            chunk = (IPCHeapChunk*)(block - sizeof(IPCHeapChunk));

            if (chunk->magic == 0xBABE0002) {
                chunk = chunk->prev;
            }

            if (chunk->magic == 0xBABE0001) {
                chunk->magic = 0xBABE0000;

                for (it = desc->head; it != NULL;) {
                    if (it->next == NULL || it->next > chunk) {
                        break;
                    }
                    it = it->next;
                }

                if (it != NULL && chunk > it) {
                    chunk->prev = it;
                    chunk->next = it->next;
                    it->next = chunk;

                    if (chunk->next != NULL) {
                        chunk->next->prev = chunk;
                    }
                } else {
                    chunk->next = desc->head;
                    desc->head = chunk;
                    chunk->prev = NULL;

                    if (chunk->next != NULL) {
                        chunk->next->prev = chunk;
                    }
                }

                if (chunk != NULL) {
                    next = chunk->next;
                    if (next == (IPCHeapChunk*)((u8*)chunk + chunk->size +
                                                sizeof(IPCHeapChunk))) {
                        chunk->next = next->next;
                        if (chunk->next != NULL) {
                            chunk->next->prev = chunk;
                        }
                        chunk->size += next->size + sizeof(IPCHeapChunk);
                    }
                }

                it = chunk->prev;
                if (it != NULL) {
                    next = it->next;
                    if (next == (IPCHeapChunk*)((u8*)it + it->size +
                                                sizeof(IPCHeapChunk))) {
                        it->next = next->next;
                        if (it->next != NULL) {
                            it->next->prev = it;
                        }
                        it->size += next->size + sizeof(IPCHeapChunk);
                    }
                }
                result = 0;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return result;
}
