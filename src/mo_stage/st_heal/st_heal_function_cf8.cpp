#pragma force_active on
typedef unsigned char u8;

extern "C" {
u8 fn_87_CF8(u8 *self, void *unused, int *a, int *b)
{
    *a = 6;
    *b = 5;
    return self[0x2a8];
}
}
