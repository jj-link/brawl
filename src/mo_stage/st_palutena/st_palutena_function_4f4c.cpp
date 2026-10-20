#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} FnBits;

extern "C" void fn_67_4F4C(FnBits *p, unsigned int v)
{
    p->b = v;
}
