#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_804FD448[];

u16 fn_8022F250(u32 arg0) {
    u8* p;
    u32 idx;

    p = (u8*)(arg0 - 8);
    if ((u32)p & 1) {
        return 0;
    }
    idx = p[4];
    if (idx < 9) {
        return *(u16*)(lbl_804FD448 + 0x289E8 + ((idx << 4) & 0xFF0));
    }
    return 0;
}
