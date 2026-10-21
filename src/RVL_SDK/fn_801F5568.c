#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern unsigned char *__GXData;

void fn_801F5568(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u32 temp_r0;
    u32 temp_r8;
    s32 temp_r9;
    s32 temp_r10;

    temp_r0 = *(u32 *)(__GXData + 0x148);
    temp_r8 = *(u32 *)(__GXData + 0x14C);
    temp_r10 = (temp_r0 >> 12) & 0x7FF;
    temp_r9 = temp_r0 & 0x7FF;
    *arg0 = temp_r10 - 0x156;
    *arg1 = temp_r9 - 0x156;
    *arg2 = (s32)(((temp_r8 >> 12) & 0x7FF) - temp_r10) + 1;
    *arg3 = (s32)((temp_r8 & 0x7FF) - temp_r9) + 1;
}
