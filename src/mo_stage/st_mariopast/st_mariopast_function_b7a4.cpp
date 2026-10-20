#pragma force_active on
typedef struct {
    unsigned int w0;
    unsigned int w1;
    unsigned int a : 14;
    unsigned int f : 7;
    unsigned int b : 11;
} Bits;

extern "C" void fn_48_B7A4(Bits *obj, unsigned int val)
{
    obj->f = val;
}
