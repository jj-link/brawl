#pragma force_active on

typedef struct {
    unsigned int f : 3;
    unsigned int rest : 29;
} BitWord;

extern "C" void fn_57_AD88(void *p, unsigned int v)
{
    BitWord *w = (BitWord *)((char *)p + 8);
    w->f = v;
}
