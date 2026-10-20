#pragma force_active on
typedef struct { unsigned int hi : 4; unsigned int rest : 28; } Bits;

extern "C" void fn_73_ACA0(unsigned int *p, unsigned int v)
{
    ((Bits *)&p[2])->hi = v;
}
