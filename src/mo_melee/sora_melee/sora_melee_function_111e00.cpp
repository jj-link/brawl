#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 a : 1;
    u8 b : 7;
};

extern "C" {
bool fn_27_111E00(u8** p)
{
    Flags* f = (Flags*)((u8*)*p + 0x1c);
    return f->a != 0;
}
}
