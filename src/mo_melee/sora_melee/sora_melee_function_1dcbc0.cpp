#pragma force_active on
typedef unsigned char u8;

extern const u8 lbl_27_rodata_2A60[160];

extern "C" int fn_27_1DCBC0(int idx)
{
    return (lbl_27_rodata_2A60[idx] >> 1) & 1;
}
