#pragma force_active on
typedef unsigned int u32;

extern "C" u32 lbl_27_bss_3210[];

extern "C" void *fn_27_147F74()
{
    u32 *entry = (u32 *)((char *)lbl_27_bss_3210 + 0x228);
    u32 *object = (u32 *)entry[0];
    return (void *)object[0x9C / 4];
}
