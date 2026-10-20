#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 3;
    unsigned int b : 3;
    unsigned int c : 26;
} Bits;

extern "C" void fn_51_DA24(Bits *p, unsigned int x)
{
    p->b = x;
}
