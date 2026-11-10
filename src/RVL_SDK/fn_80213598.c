#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
typedef struct Cell {
    u32 tag;
    u32 size;
    struct Cell *prev;
    struct Cell *next;
} Cell;
typedef struct Heap {
    void *m0;
    u32 m4;
    u32 m8;
    Cell *mC;
} Heap;
extern Heap lbl_804F65E0[8];

void *fn_80213598(s32 arg0, u32 arg1, u32 arg2) {
    Heap *heap;
    Cell *best;
    u32 mask;
    u32 sz;
    Cell *cur;
    Cell *nb;
    Cell *next;
    Cell *result;
    u32 size;
    u32 offs;
    u8 *base;
    BOOL level;

    result = NULL;
    level = OSDisableInterrupts();
    if (arg1 != 0 && arg2 != 0 && (arg2 & (arg2 - 1)) == 0) {
        if (arg2 < 0x20) {
            arg2 = 0x20;
        }
        arg1 = (arg1 + 0x1F) & ~0x1F;
        size = arg1;
        if (arg0 < 0 || arg0 >= 8 || (heap = &lbl_804F65E0[arg0], heap->m0 == NULL)) {
            result = NULL;
        } else {
                best = NULL;
                cur = heap->mC;
                mask = arg2 - 1;
                while (cur != NULL) {
                    sz = cur->size;
                    offs = mask & (arg2 - (((u32)cur + 0x10) & mask));
                    if (sz == size && offs == 0) {
                        best = cur;
                        break;
                    }
                    if (sz >= size + offs) {
                        if (best == NULL || sz < best->size) {
                            best = cur;
                        }
                    }
                    cur = cur->next;
                }
                if (best != NULL) {
                    offs = (arg2 - 1) & (arg2 - (((u32)best + 0x10) & (arg2 - 1)));
                    if (best->size > size + offs + 0x10) {
                        base = (u8 *)best + size + offs;
                        nb = (Cell *)(base + 0x10);
                        nb->tag = 0xBABE0000;
                        nb->size = best->size - size - offs - 0x10;
                        next = best->next;
                        nb->next = next;
                        if (next != NULL) {
                            next->prev = nb;
                        }
                        best->next = nb;
                        best->size = size + offs;
                    }
                    best->tag = 0xBABE0001;
                    if (best->prev != NULL) {
                        best->prev->next = best->next;
                    } else {
                        heap->mC = best->next;
                    }
                    if (best->next != NULL) {
                        best->next->prev = best->prev;
                    }
                    best->next = NULL;
                    best->prev = NULL;
                    result = (Cell *)((u8 *)best + offs + 0x10);
                    if (offs != 0) {
                        result[-1].tag = 0xBABE0002;
                        result[-1].prev = best;
                    }
                }
        }
    }
    OSRestoreInterrupts(level);
    return result;
}