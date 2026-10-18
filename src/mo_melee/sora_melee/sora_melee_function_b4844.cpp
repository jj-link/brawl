#pragma force_active on
typedef unsigned char u8;

extern "C" {
void fn_27_B4844(void* self)
{
    u8* p = (u8*)self;
    p[0x14] = ((p[0x14] | 0x80) & ~0x40) | 0x20;
}
}
