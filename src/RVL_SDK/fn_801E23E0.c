#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

extern s32 lbl_80474708[256];

u16 fn_801E23E0(u32 arg0) {
    s32 ptr;
    if (arg0 >= 0x10000) return 0;
    ptr = lbl_80474708[(arg0 & 0xFF00) >> 8];
    if (ptr != 0) {
        return *(u16 *)(ptr + ((arg0 & 0xFF) * 2));
    }
    return 0;
}
