#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_801AB078(u8* p, unsigned long flags)
{
    if (flags & 1) {
        p[0xd8] &= ~0x01;
    }
    if (flags & 2) {
        p[0xd8] &= ~0x02;
    }
    if (flags & 4) {
        p[0xd8] &= ~0x04;
    }
}
