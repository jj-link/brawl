#pragma force_active on
typedef struct {
    unsigned int p[2];
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} FnStruct;

extern "C" void fn_72_50A8(FnStruct *s, unsigned int val)
{
    s->b = val;
}
