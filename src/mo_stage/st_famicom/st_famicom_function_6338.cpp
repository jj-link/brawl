#pragma force_active on

struct Obj {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

extern "C" void fn_68_6338(Obj *s, unsigned int v)
{
    s->b = v;
}
