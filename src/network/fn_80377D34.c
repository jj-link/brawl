#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

u32 fn_80377D34(u32 **arg0, u32 arg1) {
    u32 *temp_r5;
    u16 temp_r0;

    temp_r5 = *arg0;
    temp_r0 = *(u16 *)((char *)temp_r5 + 4);
    return (temp_r5[0] * temp_r0) % arg1;
}
