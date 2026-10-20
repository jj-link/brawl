#pragma force_active on
struct Bits {
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int lo : 26;
};

struct Obj {
    unsigned int w0;
    unsigned int w1;
    Bits w2;
};

extern "C" void fn_27_C5294(Obj *p, unsigned int v)
{
    p->w2.f = v;
}
