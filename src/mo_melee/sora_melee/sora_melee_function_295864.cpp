#pragma force_active on
struct X
{
    unsigned int pad[2];
    unsigned int bits : 5;
};

extern "C" void fn_27_295864(X* p, unsigned int v)
{
    p->bits = v;
}
