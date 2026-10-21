#pragma force_active on
extern char lbl_80486440[];

struct S {
    void *vtbl;
    unsigned short a;
    signed short b;
    void *c;
};

struct S *fn_80280750(struct S *p, struct S *q)
{
    p->b = 1;
    p->vtbl = lbl_80486440;
    p->c = q;
    if (q->a != 0) {
        q->b = q->b + 1;
    }
    return p;
}
