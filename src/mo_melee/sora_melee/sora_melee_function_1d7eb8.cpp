#pragma force_active on
struct Word {
    unsigned int a : 10;
    unsigned int f : 5;
    unsigned int pad : 17;
};

struct S {
    unsigned int pad0;
    unsigned int pad4;
    Word w;
};

extern "C" void fn_27_1D7EB8(S* s, unsigned int val)
{
    s->w.f = val;
}
