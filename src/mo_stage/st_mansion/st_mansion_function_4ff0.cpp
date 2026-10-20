#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} Bits;

extern "C" void fn_47_4FF0(unsigned char *p, unsigned int v)
{
    Bits *f = (Bits *)(p + 8);
    f->b = v;
}
