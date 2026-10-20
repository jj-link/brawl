#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int hi : 9;
    unsigned int rest : 23;
} S;

extern "C" void fn_48_B4D0(S *p, unsigned int v)
{
    p->hi = v;
}
