#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 2;
    unsigned int rest : 30;
} S;

extern "C" void fn_54_673C(S *p, unsigned int v)
{
    p->hi = v;
}
