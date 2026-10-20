#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 6;
    unsigned int rest : 26;
} FnBits;

extern "C" void fn_27_2960A0(FnBits *p, unsigned int v)
{
    p->hi = v;
}
