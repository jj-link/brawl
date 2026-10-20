#pragma force_active on
typedef struct {
    unsigned int a : 2;
    unsigned int f : 2;
    unsigned int rest : 28;
} Bits;

extern "C" void fn_49_6CE8(Bits *obj, unsigned int v)
{
    obj[2].f = v;
}
