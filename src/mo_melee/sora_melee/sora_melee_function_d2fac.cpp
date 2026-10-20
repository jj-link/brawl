#pragma force_active on
struct Bits {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
};

struct Obj {
    unsigned int w0;
    unsigned int w1;
    struct Bits f;
};

extern "C" void fn_27_D2FAC(struct Obj *o, unsigned int v)
{
    o->f.b = v;
}
