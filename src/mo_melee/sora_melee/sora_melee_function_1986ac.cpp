#pragma force_active on
typedef unsigned int u32;

struct Word8 {
    char pad[8];
    u32 hi : 8;
    u32 mid : 4;
    u32 lo : 20;
};

extern "C" {
void fn_27_1986AC(Word8 *p, u32 v)
{
    p->mid = v;
}
}
