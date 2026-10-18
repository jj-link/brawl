#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_61_E674(char *self, u32 a, u32 b)
{
    *(u32 *)(self + 0x5b0) = a;
    *(u32 *)(self + 0x5b8) = b;
}
}
