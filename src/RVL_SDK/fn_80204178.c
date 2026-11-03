#include <revolution/MEM/mem_expHeap.h>
#include <string.h>
#pragma force_active on

static inline void* AddU32ToPtr(const void* p, u32 size)
{
    return (void*)((u32)p + size);
}

static inline void* SubU32ToPtr(const void* p, u32 size)
{
    return (void*)((u32)p - size);
}

static inline s32 GetOffsetFromPtr(const void* a, const void* b)
{
    return (u32)b - (u32)a;
}

static inline void FillMemory(MEMiExpHeapHead* exp, void* ptr, u32 size)
{
    if (*(u32*)((char*)exp - 4) & 1) {
        memset(ptr, 0, size);
    }
}

static inline void GetRegion(void** region, MEMiExpHeapMBlock* block)
{
    region[0] = SubU32ToPtr(block, block->align);
    region[1] = AddU32ToPtr(
        AddU32ToPtr(block, sizeof(MEMiExpHeapMBlock)), block->size);
}

static inline MEMiExpHeapMBlock* RemoveBlock(
    MEMiExpHeapMBlockList* list, MEMiExpHeapMBlock* block)
{
    MEMiExpHeapMBlock* prev = block->prev;
    MEMiExpHeapMBlock* next = block->next;

    if (prev) {
        prev->next = next;
    } else {
        list->head = next;
    }

    if (next) {
        next->prev = prev;
    } else {
        list->tail = prev;
    }

    return prev;
}

static inline void InsertBlock(
    MEMiExpHeapMBlockList* list,
    MEMiExpHeapMBlock* prev,
    MEMiExpHeapMBlock* block)
{
    MEMiExpHeapMBlock* next;

    block->prev = prev;
    if (prev) {
        next = prev->next;
        prev->next = block;
    } else {
        next = list->head;
        list->head = block;
    }

    block->next = next;
    if (next) {
        next->prev = block;
    } else {
        list->tail = block;
    }
}

static inline void AppendBlock(
    MEMiExpHeapMBlockList* list, MEMiExpHeapMBlock* block)
{
    InsertBlock(list, list->tail, block);
}

static inline MEMiExpHeapMBlock* InitBlock(void** region, u16 state)
{
    MEMiExpHeapMBlock* block = region[0];

    block->state = state;
    block->settings = 0;
    block->size = GetOffsetFromPtr(
        AddU32ToPtr(block, sizeof(MEMiExpHeapMBlock)), region[1]);
    block->prev = NULL;
    block->next = NULL;
    return block;
}

void* fn_80204178(
    MEMiExpHeapHead* exp,
    MEMiExpHeapMBlock* block,
    void* memPtr,
    u32 size,
    u16 allocDir)
{
    void* region[2];
    void* usedRegion[2];
    void* end = AddU32ToPtr((void*)size, (u32)memPtr);
    MEMiExpHeapMBlock* used;
    MEMiExpHeapMBlock* prev;

    usedRegion[0] = SubU32ToPtr(memPtr, sizeof(MEMiExpHeapMBlock));
    usedRegion[1] = end;
    GetRegion(region, block);
    prev = RemoveBlock(&exp->freeMBlocks, block);

    if ((u32)GetOffsetFromPtr(region[0], usedRegion[0]) < 0x14) {
        usedRegion[0] = region[0];
    } else {
        void* freeRegion[2];
        MEMiExpHeapMBlock* freeBlock;

        freeRegion[0] = region[0];
        freeRegion[1] = usedRegion[0];
        freeBlock = InitBlock(freeRegion, 0x4652);
        InsertBlock(&exp->freeMBlocks, prev, freeBlock);
        prev = freeBlock;
    }

    if ((u32)GetOffsetFromPtr(usedRegion[1], region[1]) < 0x14) {
        usedRegion[1] = region[1];
    } else {
        void* freeRegion[2];
        MEMiExpHeapMBlock* freeBlock;

        freeRegion[0] = usedRegion[1];
        freeRegion[1] = region[1];
        freeBlock = InitBlock(freeRegion, 0x4652);
        InsertBlock(&exp->freeMBlocks, prev, freeBlock);
    }

    FillMemory(exp, usedRegion[0],
               GetOffsetFromPtr(usedRegion[0], usedRegion[1]));

    {
        void* allocRegion[2];

        allocRegion[0] = SubU32ToPtr(memPtr, sizeof(MEMiExpHeapMBlock));
        allocRegion[1] = usedRegion[1];
        used = InitBlock(allocRegion, 0x5544);
    }

    used->allocDir = allocDir;
    used->align = GetOffsetFromPtr(usedRegion[0], used);
    used->group = exp->group;
    AppendBlock(&exp->usedMBlocks, used);
    return memPtr;
}
