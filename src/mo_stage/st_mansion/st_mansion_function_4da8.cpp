#pragma force_active on
typedef struct {
    unsigned int hi : 2;
    unsigned int lo : 30;
} Bits;

extern "C" void fn_47_4DA8(Bits *p, unsigned int v)
{
    p[2].hi = v;
}
