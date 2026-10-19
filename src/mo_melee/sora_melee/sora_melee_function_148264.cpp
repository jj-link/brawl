#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern u32 lbl_27_bss_3210[];

u32 fn_27_148264(u32 unused, s32 id) {
    switch (id) {
    case 0x1f: {
        u32* p = (u32*)lbl_27_bss_3210[0x174 / 4];
        return p[0x90 / 4];
    }
    case 0x5: {
        u32* p = (u32*)lbl_27_bss_3210[0x3c / 4];
        return p[0x154 / 4];
    }
    default:
        return 0;
    }
}
}
