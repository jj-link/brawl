#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct fn_27_C9940_arg {
    u8 pad[8];
    u32 unk8;
};

extern "C" s32 fn_27_C9940(fn_27_C9940_arg* p)
{
    return ((s32)((p->unk8 << 6) & 0xF0000000)) >> 29;
}
