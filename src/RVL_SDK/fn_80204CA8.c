typedef struct OSModuleHeader OSModuleHeader;
typedef int bool;
#include <revolution/MEM.h>
#include <revolution/OS.h>
#pragma force_active on

static MEMiFrmHeapHead* GetFrmHeapHeadPtrFromHeapHead_(const MEMiHeapHead* heap) {
    return AddU32ToPtr(heap, sizeof(MEMiHeapHead));
}

static MEMiHeapHead* GetHeapHeadPtrFromFrmHeapHead_(const MEMiFrmHeapHead* frm) {
    return SubU32ToPtr(frm, sizeof(MEMiHeapHead));
}

static void* AllocFromHead_(MEMiFrmHeapHead* frm, u32 size, s32 align) {
    void* start;
    void* end;
    start = ROUND_UP_PTR(GetUIntPtr(frm->head), align);
    end = AddU32ToPtr(start, size);
    if (end > frm->tail) {
        return NULL;
    }
    FillAllocMemory(GetHeapHeadPtrFromFrmHeapHead_(frm), frm->head,
                    GetOffsetFromPtr(frm->head, end));
    frm->head = end;
    return start;
}

BOOL fn_80204CA8(MEMiHeapHead* heap, u32 id) {
    MEMiFrmHeapState* state;
    MEMiFrmHeapHead* frm;
    BOOL success;
    u8* head;
    LockHeap(heap);
    frm = GetFrmHeapHeadPtrFromHeapHead_(heap);
    head = frm->head;
    state = AllocFromHead_(frm, sizeof(MEMiFrmHeapState), 4);
    if (state == NULL) {
        success = FALSE;
    } else {
        state->id = id;
        state->head = head;
        state->tail = frm->tail;
        state->next = frm->states;
        frm->states = state;
        success = TRUE;
    }
    UnlockHeap(heap);
    return success;
}
