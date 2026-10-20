#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    u8 pad[8];
    u32 word;
};

extern "C" {
s32 fn_27_1B1B68(FnObj* p)
{
    u32 w = p->word;
    return ((s32)(((w << 6) | (w >> 26)) & 0xF0000000)) >> 29;
}
}
