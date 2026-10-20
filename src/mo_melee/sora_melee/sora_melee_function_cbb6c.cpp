#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} BitWord;

extern "C" void fn_27_CBB6C(void *self, unsigned int v)
{
    BitWord *w = (BitWord *)((char *)self + 8);
    w->b = v;
}
