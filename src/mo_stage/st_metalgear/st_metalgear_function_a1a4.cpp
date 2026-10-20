#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 4;
    unsigned int f : 4;
    unsigned int b : 24;
} S;

extern "C" void fn_71_A1A4(S *p, unsigned int v)
{
    p->f = v;
}
