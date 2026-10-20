#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int f : 2;
    unsigned int g : 30;
} S;

extern "C" void fn_52_7580(S *p, unsigned int v)
{
    p->f = v;
}
