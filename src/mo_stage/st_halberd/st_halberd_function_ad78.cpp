#pragma force_active on
typedef struct {
    unsigned int pad0 : 4;
    unsigned int f : 2;
    unsigned int pad1 : 26;
} BitWord;

extern "C" void fn_57_AD78(void *p, unsigned int v)
{
    BitWord *w = (BitWord *)((char *)p + 8);
    w->f = v;
}
