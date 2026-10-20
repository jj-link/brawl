#pragma force_active on
typedef struct {
    unsigned int a : 7;
    unsigned int b : 7;
    unsigned int c : 18;
} BitWord;

typedef struct {
    unsigned int w0;
    unsigned int w1;
    BitWord f;
} BitBlock;

extern "C" void fn_48_B954(BitBlock *p, unsigned int v)
{
    p->f.b = v;
}
