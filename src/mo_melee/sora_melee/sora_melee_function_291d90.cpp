#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FnObj27 {
    u8 pad[8];
    u32 unk8;
};

extern "C" {
s32 fn_27_291D90(FnObj27 *p)
{
    u32 v = p->unk8;
    return (s32)(((v >> 22) & 0xF) << 28) >> 29;
}
}
