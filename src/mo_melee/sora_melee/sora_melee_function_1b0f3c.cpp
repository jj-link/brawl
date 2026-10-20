#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Fn27Src {
    u8 pad[0x8];
    s32 flag;
};

extern "C" u8* fn_27_1B0F3C(Fn27Src* p, s32 idx)
{
    s32 n = (p->flag >> 27) + idx;
    if (n >= 10) {
        n -= 10;
    }
    return (u8*)p + n * 0x34 + 0xc;
}
