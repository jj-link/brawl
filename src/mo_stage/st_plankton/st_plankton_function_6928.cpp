#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} S;

extern "C" void fn_74_6928(S *p, unsigned int v)
{
    p->b = v;
}
