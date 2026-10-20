#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_109450(void* r3)
{
    u8* b = (u8*)r3;
    u8* p = *(u8**)(b + 0x15c);
    p[0x10a0] = 1;
    b[0x6c] = (u8)(b[0x6c] & 0xFFFFFF9F);
    b[0x6e] = (u8)(b[0x6e] & 0xFFFFFFFB);
}
