#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 30;
} Bits;

void fn_74_6A0C(Bits *p, unsigned int v)
{
    p->a = v;
}
}
