#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int f : 2;
    unsigned int b : 26;
} W;

extern "C" void fn_72_52A0(W *p, unsigned int v)
{
    ((W *)((char *)p + 8))->f = v;
}
