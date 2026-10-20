#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} Bits;

typedef struct {
    unsigned int pad[2];
    Bits bits;
} Outer;

extern "C" void fn_71_A168(Outer *p, unsigned int v)
{
    p->bits.b = v;
}
