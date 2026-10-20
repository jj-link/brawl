#pragma force_active on
// attempt 1: bitfield store lowering
typedef struct Bit3 {
    unsigned char pad[8];
    unsigned int f : 3;
} Bit3;

extern "C" void fn_54_6698(Bit3* s, unsigned int v)
{
    s->f = v;
}
