#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_8030300C(u8* a, const u8* b)
{
    a[0x22] = *b;
}
