#pragma force_active on
typedef unsigned char u8;

extern "C" int fn_71_2348(void *self)
{
    return (((u8 *)self)[0x1dc] >> 7 & 1) ^ 1;
}
