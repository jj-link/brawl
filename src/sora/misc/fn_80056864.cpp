typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u16 lbl_8042D5C0[];
extern s32 lbl_8059CE44;

#pragma force_active on
extern "C" {
s32 fn_80056864(s32 arg0)
{
    s32 var_r4 = -1;
    if (arg0 >= 0 && arg0 < lbl_8059CE44) {
        var_r4 = (lbl_8042D5C0[arg0] >> 6) & 0x3FF;
    }
    return var_r4;
}
}
