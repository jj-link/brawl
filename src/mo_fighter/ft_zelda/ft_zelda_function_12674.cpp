#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 pad0 : 1;
    u8 flag : 1;
    u8 rest : 6;
};

extern "C" bool fn_104_12674(void *self)
{
    return ((Flags *)((u8 *)self + 0xa4))->flag != 0;
}
