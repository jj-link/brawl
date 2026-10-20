#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 4;
    unsigned int rest : 28;
} Bits;

extern "C" void fn_47_4FD0(Bits *obj, unsigned int val)
{
    obj->hi = val;
}
