#pragma force_active on
typedef struct {
    unsigned int a[2];
    unsigned int hi : 2;
    unsigned int rest : 30;
} S;

extern "C" void fn_72_4FFC(S *p, unsigned int v)
{
    p->hi = v;
}
