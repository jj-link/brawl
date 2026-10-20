#pragma force_active on
typedef struct SoBits {
    unsigned int pad[2];
    unsigned int f : 3;
    unsigned int rest : 29;
} SoBits;

extern "C" void fn_27_295E48(SoBits *p, unsigned int v)
{
    p->f = v;
}
