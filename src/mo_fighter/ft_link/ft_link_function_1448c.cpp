#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 a : 1;
    u8 flag : 1;
    u8 rest : 6;
};

extern "C" {
bool fn_93_1448C(void *self)
{
    Flags *f = (Flags *)((u8 *)self + 0xa4);
    return f->flag;
}
}
