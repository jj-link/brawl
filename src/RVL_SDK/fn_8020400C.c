#include <revolution/OS/OSMutex.h>
#pragma force_active on
typedef struct Node {
    char pad[12];
    unsigned int list[3];
    unsigned int start;
    unsigned int end;
} Node;
extern unsigned int lbl_804E8A58[4];
extern OSMutex lbl_804E8A68;
extern Node *fn_80204FA8(void *, Node *);
extern Node *fn_80203D0C(void *, unsigned int);
extern void fn_80204F3C(void *, void *);
void fn_8020400C(unsigned int *addr)
{
    Node *b, *a, *c, *result, *outer;
    void *list;
    OSLockMutex(&lbl_804E8A68);
    a = 0;
    list = lbl_804E8A58;
    while ((a = fn_80204FA8(lbl_804E8A58, a)) != 0) {
        if (a->start <= (unsigned int)addr && (unsigned int)addr < a->end) {
            b = 0;
            while ((b = fn_80204FA8(a->list, b)) != 0) {
                if (b->start <= (unsigned int)addr && (unsigned int)addr < b->end) {
                    Node *inner;
                    c = 0;
                    while ((c = fn_80204FA8(b->list, c)) != 0) {
                        if (c->start <= (unsigned int)addr && (unsigned int)addr < c->end) {
                            Node *child = fn_80203D0C(c->list, (unsigned int)addr);
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
    fn_80204F3C(list, addr);
    OSUnlockMutex(&lbl_804E8A68);
    *addr = 0;
}