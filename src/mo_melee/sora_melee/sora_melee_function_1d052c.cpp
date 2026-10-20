#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 6;
    unsigned int lo : 26;
} BitS;

extern "C" {
void fn_27_1D052C(BitS *p, unsigned int v)
{
    p->hi = v;
}
}
