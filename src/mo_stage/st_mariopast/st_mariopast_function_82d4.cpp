#pragma force_active on
typedef struct Pair {
    void *a;
    void *b;
} Pair;

extern "C" void fn_48_82D4(Pair *p)
{
    p->a = 0;
    p->b = 0;
}
