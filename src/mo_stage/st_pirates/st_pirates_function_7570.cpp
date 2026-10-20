#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int pad : 4;
    unsigned int a : 2;
} S;

extern "C" void fn_52_7570(S *p, unsigned int v)
{
    p->a = v;
}
