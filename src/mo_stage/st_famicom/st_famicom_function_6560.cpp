#pragma force_active on
typedef struct {
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int lo : 24;
} Bits;

extern "C" void fn_68_6560(Bits *p, unsigned int v)
{
    ((Bits *)((char *)p + 8))->f = v;
}
