#pragma force_active on
struct Bits {
    unsigned int hi : 20;
    unsigned int mid : 10;
    unsigned int lo : 2;
};

extern "C" void fn_27_1A6AD0(void *p, unsigned int v)
{
    Bits *b = (Bits *)((char *)p + 8);
    b->mid = v;
}
