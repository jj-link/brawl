#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int hi : 2;
    unsigned int f : 2;
    unsigned int lo : 28;
} S;

extern "C" void fn_71_9F7C(S *p, unsigned int v)
{
    p->f = v;
}
