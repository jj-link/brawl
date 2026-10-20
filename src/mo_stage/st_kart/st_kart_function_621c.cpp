#pragma force_active on
typedef struct {
    int a;
    int b;
} ResetPair;

extern "C" void fn_49_621C(ResetPair *p)
{
    p->b = -1;
    p->a = -1;
}
