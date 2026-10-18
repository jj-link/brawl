#pragma force_active on
typedef unsigned char u8;

struct Flags {
    char pad[0x54];
    u8 bit : 1;
};

extern "C" bool fn_27_14A48(Flags* p)
{
    return p->bit;
}
