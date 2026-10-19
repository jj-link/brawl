#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern u8 lbl_27_bss_3210[];

u32 fn_27_149784(u32, s32 p2)
{
    switch (p2) {
    case 0xb:
        return *(u32*)((u8*)*(u32*)(lbl_27_bss_3210 + 0x84) + 0x7c);
    case 0x5:
        return *(u32*)((u8*)*(u32*)(lbl_27_bss_3210 + 0x3c) + 0x110);
    default:
        return 0;
    }
}
}
