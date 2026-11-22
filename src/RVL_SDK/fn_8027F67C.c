#include <types.h>
#pragma force_active on
#pragma optimization_level 0
extern void *(*lbl_8059EF40)(int, int);
typedef struct Node { struct Node *next; } Node;
typedef struct Heap {
    char pad0[0x1c]; int blocks; char pad20[8]; int total;
    char pad2c[0xa04]; Node *chain; char *start; char *end; char *current;
    char padA40[4]; Node *freeList[17]; int sizes[154]; int counts[17];
} Heap;

void *fn_8027F67C(Heap *h, int index)
{
    Node *block;
    Node *sp54;
    void *sp50;
    void *sp4c;
    Node *sp48;
    Node *sp44;
    Node *sp40;
    int sp3c;
    char *sp38;
    char *sp34;
    int sp30;
    int sp2c;
    int sp28;
    int sp24;
    int sp20;
    char *sp1c;
    Node *sp18;
    int sp14;
    int sp10;
    int spc;
    int sp8;

    h->counts[index]++;
    h->total += h->sizes[index];
    (void)&h->freeList[index];
    sp54 = h->freeList[index];
    if (sp54 != 0) {
        h->freeList[index] = sp54->next;
        sp50 = sp54;
    } else {
        if (index < 13) {
            sp8 = index;
            spc = h->sizes[sp8];
            sp10 = spc;
            if (h->current + spc > h->end) {
                sp14 = 0x2040;
                sp18 = lbl_8059EF40(sp14, 0x40);
                sp18->next = h->chain;
                h->chain = sp18;
                h->start = (char *)sp18 + 0x40;
                h->current = h->start;
                h->end = h->start + 0x2000;
                h->blocks++;
            }
            sp1c = h->current;
            h->current += spc;
            sp20 = h->counts[sp8];
            while (sp10 < 0x200) {
                if (h->current + spc >= h->end)
                    break;
                sp40 = (Node *)h->current;
                sp44 = sp40;
                h->counts[sp8]--;
                sp44->next = h->freeList[sp8];
                h->freeList[sp8] = sp44;
                h->current += spc;
                sp10 += spc;
            }
            h->counts[sp8] = sp20;
            sp4c = sp1c;
        } else {
            sp24 = index;
            sp28 = h->sizes[sp24];
            sp2c = 0x2040;
            block = lbl_8059EF40(sp2c, 0x40);
            if (h->chain != 0) {
                block->next = h->chain->next;
                h->chain->next = block;
            } else {
                block->next = 0;
                h->chain = block;
            }
            h->blocks++;
            sp30 = h->counts[sp24];
            sp34 = (char *)block + 0x40;
            sp38 = sp34 + sp28;
            sp3c = sp28;
            while (sp3c < 0x2000) {
                sp48 = (Node *)sp38;
                h->counts[sp24]--;
                sp48->next = h->freeList[sp24];
                h->freeList[sp24] = sp48;
                sp38 += sp28;
                sp3c += sp28;
            }
            h->counts[sp24] = sp30;
            sp4c = sp34;
        }
        sp50 = sp4c;
    }
    return sp50;
}
