#pragma force_active on
struct BF {
    unsigned int a : 10;
    unsigned int b : 5;
    unsigned int c : 17;
};

struct Obj {
    unsigned int w0;
    unsigned int w1;
    BF f;
};

extern "C" void fn_27_19E000(Obj *p, unsigned int v)
{
    p->f.b = v;
}
