#pragma force_active on
typedef struct {
    unsigned int x0;
    unsigned int x1;
    unsigned int x2;
    unsigned int x3;
} Blk;

extern void fn_8038F7C8(void *, void *, void *);

void fn_8038FF7C(Blk *a, Blk *b, const Blk *c)
{
    unsigned int t0, t1, t2, t3;

    t0 = a->x0;
    a->x0 = c->x0;
    t1 = a->x1;
    a->x1 = c->x1;
    t2 = a->x2;
    a->x2 = c->x2;
    t3 = a->x3;
    a->x3 = c->x3;
    fn_8038F7C8(a, b, (void *)c);
    b->x0 ^= t0;
    b->x1 ^= t1;
    b->x2 ^= t2;
    b->x3 ^= t3;
}
