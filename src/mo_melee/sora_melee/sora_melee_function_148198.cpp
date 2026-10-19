#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" u32 lbl_27_bss_3210[];

extern "C" s32 fn_27_148198(s32 unused, s32 id) {
    switch (id) {
    case 0x1d: {
        u8* base = (u8*)lbl_27_bss_3210;
        s32 p = *(s32*)(base + 0x15c);
        return *(s32*)(p + 0x90);
    }
    case 5: {
        u8* base = (u8*)lbl_27_bss_3210;
        s32 p = *(s32*)(base + 0x3c);
        return *(s32*)(p + 0x150);
    }
    default:
        return 0;
    }
}
