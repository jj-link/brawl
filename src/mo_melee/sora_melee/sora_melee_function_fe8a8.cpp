#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 4;
    unsigned int rest : 28;
} BitField8;

extern "C" {
void fn_27_FE8A8(BitField8 *p, unsigned int v)
{
    p->hi = v;
}
}
