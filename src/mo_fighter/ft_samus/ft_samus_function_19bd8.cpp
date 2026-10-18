#pragma force_active on
typedef struct {
    void *a;
    void *b;
} Pair;

extern "C" void fn_94_19BD8(Pair *p, void *x, void *y)
{
    p->a = x;
    p->b = y;
}
