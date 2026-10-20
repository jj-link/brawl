#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern const u32 lbl_90_data_2A64[5];
extern const s32 lbl_90_data_2A78[5];

extern "C" int fn_90_726C(u32 *base, s32 idx, s32 off)
{
    if ((u32)idx >= 5 || (u32)idx >= lbl_90_data_2A64[idx]) {
        return 0;
    }
    idx = off + lbl_90_data_2A78[idx];
    return (*(u32 *)((char *)(base + idx / 32) + 0x244) & (1U << (idx & 31))) != 0;
}
