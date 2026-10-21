#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int pad : 6;
    unsigned int a : 3;
    unsigned int rest : 23;
} S;

extern "C" void fn_66_11388(S *p, unsigned int v)
{
    p->a = v;
}
