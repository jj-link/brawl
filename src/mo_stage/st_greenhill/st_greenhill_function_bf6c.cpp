#pragma force_active on
typedef struct {
    unsigned int a : 6;
    unsigned int b : 3;
    unsigned int c : 23;
} F;

extern "C" void fn_72_BF6C(F *p, unsigned int v)
{
    p[2].b = v;
}
