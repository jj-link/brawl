#include <types.h>
#pragma force_active on
#pragma optimization_level 0

extern void *(*lbl_8059EF40)(int, int);

typedef struct Node {
    struct Node *next;
} Node;

typedef struct Heap {
    char pad0[0x10];
    int largeCount;
    int largeSize;
    int largeMax;
    int blocks;
    char pad20[8];
    int total;
    char pad2c[0xa04];
    Node *chain;
    char *start;
    char *end;
    char *current;
    char padA40[4];
    Node *freeList[17];
    int sizes[17];
    signed char small[516];
    int large[8];
    int counts[17];
} Heap;

void *fn_8027F28C(Heap *h, int size)
{
    void *sp64;
    int sp60;
    Node *sp5c;
    void *sp58;
    Node *sp54;
    Node *sp50;
    Node *sp4c;
    int sp48;
    char *sp44;
    char *sp40;
    int sp3c;
    Node *sp38;
    int sp34;
    int sp30;
    int sp2c;
    int sp28;
    char *sp24;
    Node *sp20;
    int sp1c;
    int sp18;
    int sp14;
    int sp10;
    int spc;
    int sp8;

    if (size <= 0x2000) {
        if (size <= 0x200) {
            spc = h->small[size];
        } else {
            spc = h->large[(size - 1) >> 10];
        }

        sp8 = spc;
        sp60 = sp8;
        h->counts[sp60]++;
        h->total += h->sizes[sp60];
        sp5c = h->freeList[sp60];

        if (sp5c != 0) {
            h->freeList[sp60] = sp5c->next;
            sp64 = sp5c;
        } else {
            if (sp60 < 13) {
                sp10 = sp60;
                sp14 = h->sizes[sp10];
                sp18 = sp14;

                if (h->current + sp14 > h->end) {
                    sp1c = 0x2040;
                    sp20 = lbl_8059EF40(sp1c, 0x40);
                    sp20->next = h->chain;
                    h->chain = sp20;
                    h->start = (char *)sp20 + 0x40;
                    h->current = h->start;
                    h->end = h->start + 0x2000;
                    h->blocks++;
                }

                sp24 = h->current;
                h->current += sp14;
                sp28 = h->counts[sp10];

                while (sp18 < 0x200) {
                    if (h->current + sp14 >= h->end) {
                        break;
                    }
                    sp4c = (Node *)h->current;
                    sp50 = sp4c;
                    h->counts[sp10]--;
                    sp50->next = h->freeList[sp10];
                    h->freeList[sp10] = sp50;
                    h->current += sp14;
                    sp18 += sp14;
                }

                h->counts[sp10] = sp28;
                sp58 = sp24;
            } else {
                sp2c = sp60;
                sp30 = h->sizes[sp2c];
                sp34 = 0x2040;
                sp38 = lbl_8059EF40(sp34, 0x40);

                if (h->chain != 0) {
                    sp38->next = h->chain->next;
                    h->chain->next = sp38;
                } else {
                    sp38->next = 0;
                    h->chain = sp38;
                }

                h->blocks = 1 + h->blocks;
                sp3c = h->counts[sp2c];
                sp40 = (char *)(sp38 + 16);
                sp44 = sp40 + sp30;
                sp48 = sp30;

                while (sp48 < 0x2000) {
                    sp54 = (Node *)sp44;
                    h->counts[sp2c]--;
                    sp54->next = h->freeList[sp2c];
                    h->freeList[sp2c] = sp54;
                    sp44 += sp30;
                    sp48 += sp30;
                }

                h->counts[sp2c] = sp3c;
                sp58 = sp40;
            }

            sp64 = sp58;
        }
    } else {
        h->largeCount++;
        h->largeSize += size;
        if (h->largeSize > h->largeMax) {
            h->largeMax = h->largeSize;
        }
        sp64 = lbl_8059EF40(size, 0x40);
    }

    return sp64;
}
