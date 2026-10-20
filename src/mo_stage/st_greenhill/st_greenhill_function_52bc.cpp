#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int f : 4;
    unsigned int rest : 28;
} S;

extern "C" {
void fn_72_52BC(S *p, unsigned int v)
{
    p->f = v;
}
}
