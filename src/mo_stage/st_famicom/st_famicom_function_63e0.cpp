#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int rest : 30;
} S;

extern "C" void fn_68_63E0(S *p, unsigned int v)
{
    p->a = v;
}
