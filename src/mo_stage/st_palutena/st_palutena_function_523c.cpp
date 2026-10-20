#pragma force_active on
typedef struct {
    unsigned int pre[2];
    unsigned int a : 4;
    unsigned int f : 4;
    unsigned int b : 24;
} Bits;

extern "C" void fn_67_523C(Bits *p, unsigned int v)
{
    p->f = v;
}
