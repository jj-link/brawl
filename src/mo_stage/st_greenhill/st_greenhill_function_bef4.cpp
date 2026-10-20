#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int p : 3;
    unsigned int f : 3;
    unsigned int q : 26;
} FnStruct;

extern "C" void fn_72_BEF4(FnStruct *s, unsigned int v)
{
    s->f = v;
}
