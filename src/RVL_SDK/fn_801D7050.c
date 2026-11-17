#pragma force_active on
typedef struct Block {
    struct Block *prev;
    struct Block *next;
    int size;
} Block;

typedef struct Heap {
    int size;
    Block *free;
    Block *allocated;
} Heap;

extern Heap *lbl_805A068C;
extern int lbl_805A0688;
extern unsigned int lbl_805A0680;
extern void *lbl_805A0684;
extern int lbl_8059E9B0;

void *fn_801D7050(void *arenaStart, void *arenaEnd, int maxHeaps)
{
    unsigned int arraySize = maxHeaps * sizeof(Heap);
    int i;
    Heap *hd;

    lbl_805A068C = (Heap *)arenaStart;
    lbl_805A0688 = maxHeaps;

    for (i = 0; i < lbl_805A0688; i++) {
        hd = &lbl_805A068C[i];
        hd->size = -1;
        hd->free = hd->allocated = 0;
    }

    lbl_8059E9B0 = -1;
    arenaStart = (void *)((unsigned int)lbl_805A068C + arraySize);
    arenaStart = (void *)(((unsigned int)arenaStart + 31) & ~31);
    lbl_805A0684 = arenaStart;
    lbl_805A0680 = (unsigned int)arenaEnd & ~31;
    return arenaStart;
}
