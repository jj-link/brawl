#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 2;
    unsigned int rest : 30;
} S;

extern "C" void fn_68_6318(S *p, unsigned int v)
{
    p->hi = v;
}
