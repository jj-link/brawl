#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 a : 1;
    u8 b : 1;
    u8 c : 1;
    u8 d : 1;
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 1;
};

extern "C" {
bool fn_123_13D64(void *p)
{
    return ((Flags *)((u8 *)p + 0xa4))->b;
}
}
