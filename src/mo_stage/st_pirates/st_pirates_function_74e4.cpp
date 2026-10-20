#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Flags;

extern "C" void fn_52_74E4(Flags *p, unsigned int v)
{
    p->b = v;
}
