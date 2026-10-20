#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int top : 3;
    unsigned int rest : 29;
} S;

extern "C" {
void fn_72_BEE4(S *p, unsigned int v)
{
    p->top = v;
}
}
