#include <types.h>
#pragma force_active on
extern void *fn_80204768(void *, int, int);
extern void fn_80204818(void *, void *);
extern void *fn_803A976C(void *, int, unsigned int);

typedef struct {
    void *heap;
    int count;
    void *a;
    void *b;
} State;

void fn_803C4168(void *obj, int count, void *heap) {
    State *p;
    int n, size1, size2;
    if (obj != 0) {
        p = (State *)((char *)obj + 0x1c);
        n = count * 2;
        if (p->a == 0 && p->b == 0) {
            size2 = n << 9;
            size1 = n * 0x28;
            p->a = heap == 0 ? 0 : fn_80204768(heap, size1, 4);
            p->b = heap == 0 ? 0 : fn_80204768(heap, size2, 4);
            if (p->a != 0 && p->b != 0) {
                fn_803A976C(p->a, 0, size1);
                fn_803A976C(p->b, 0, size2);
                p->heap = heap;
                p->count = count;
            } else if (p != 0) {
                if (p->a != 0 && p->heap != 0)
                    fn_80204818(p->heap, p->a);
                if (p->b != 0 && p->heap != 0)
                    fn_80204818(p->heap, p->b);
                if (p != 0) {
                    p->heap = 0;
                    p->count = 0;
                    p->a = 0;
                    p->b = 0;
                }
            }
        }
    }
}
