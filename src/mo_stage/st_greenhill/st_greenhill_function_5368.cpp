#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int hi : 8;
    unsigned int f : 4;
    unsigned int lo : 20;
} S;

extern "C" void fn_72_5368(S *p, unsigned int v)
{
    p->f = v;
}
