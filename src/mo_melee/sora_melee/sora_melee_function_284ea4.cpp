#pragma force_active on
typedef unsigned char u8;

extern "C" {
bool fn_27_284EA4(u8* self)
{
    u8* p = *(u8**)(self + 0x944);
    return p != (self + 0x92c);
}
}
