#include <revolution/OS/OSMutex.h>
#pragma force_active on

typedef struct Node {
    char pad[12];
    unsigned int list[3];
    unsigned int start;
    unsigned int end;
} Node;

typedef union ByteWord {
    struct {
        unsigned int high:24;
        unsigned int low:8;
    } bits;
    unsigned int word;
} ByteWord;

extern unsigned int lbl_804E8A58[4];
extern OSMutex lbl_804E8A68;
extern s32 lbl_805A0B58;
extern Node *fn_80204FA8(void *, Node *);
extern Node *fn_80203D0C(void *, unsigned int);
extern void fn_80204EB4(void *, unsigned short);
extern void fn_80204ECC(void *, void *);

void fn_80203E4C(unsigned int *self, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4)
{
    Node *b, *a, *c, *result, *outer;
    unsigned int addr;
    void *list;
    ByteWord value;

    self[0] = arg1;
    self[6] = arg2;
    self[7] = arg3;
    value.word = 0;
    value.bits.low = arg4;
    self[14] = value.word;
    fn_80204EB4(self + 3, 4);
    if (lbl_805A0B58 == 0) {
        fn_80204EB4(lbl_804E8A58, 4);
        OSInitMutex(&lbl_804E8A68);
        lbl_805A0B58 = 1;
    }
    OSInitMutex((OSMutex *)(self + 8));
    OSLockMutex(&lbl_804E8A68);

    addr = (unsigned int)self;
    a = 0;
    list = lbl_804E8A58;
    while ((a = fn_80204FA8(lbl_804E8A58, a)) != 0) {
        if (a->start <= addr && addr < a->end) {
            b = 0;
            while ((b = fn_80204FA8(a->list, b)) != 0) {
                if (b->start <= addr && addr < b->end) {
                    Node *inner;
                    c = 0;
                    while ((c = fn_80204FA8(b->list, c)) != 0) {
                        if (c->start <= addr && addr < c->end) {
                            Node *child = fn_80203D0C(c->list, addr);
                            if (child != 0)
                                inner = child;
                            else
                                inner = c;
                            goto found_c;
                        }
                    }
                    inner = 0;
found_c:
                    if (inner != 0)
                        result = inner;
                    else
                        result = b;
                    goto found_b;
                }
            }
            result = 0;
found_b:
            if (result != 0)
                outer = result;
            else
                outer = a;
            goto found_a;
        }
    }
    outer = 0;
found_a:
    if (outer != 0)
        list = outer->list;
    fn_80204ECC(list, self);
    OSUnlockMutex(&lbl_804E8A68);
}