#pragma force_active on
extern int lbl_805A0B60;

typedef unsigned int u32;

void fn_80207CB0(u32 *arg0) {
    u32 *temp_r3;
    temp_r3 = (u32 *)((char *)lbl_805A0B60 + arg0[6] * 0x70);
    temp_r3[1] = (temp_r3[1] & 0xFFFFFFF7) | 0x10000000;
}
