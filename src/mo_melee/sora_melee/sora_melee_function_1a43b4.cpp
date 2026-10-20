#pragma force_active on
typedef struct Bits {
    int pad[2];
    unsigned int hi : 10;
    unsigned int lo : 22;
} Bits;

extern "C" void fn_27_1A43B4(Bits *p, unsigned int v)
{
    p->hi = v;
}
