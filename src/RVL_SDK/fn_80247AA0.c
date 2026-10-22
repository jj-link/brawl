#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern unsigned char lbl_8052C9B8[0x408];
u8 fn_802482C4(void);

u8 fn_80247AA0(void* arg0) {
    u8 temp;

    if (lbl_8052C9B8[0x400] != 0) {
        return 2;
    }
    if (arg0 == 0) {
        return 5;
    }
    temp = fn_802482C4();
    if (temp != 0) {
        return temp;
    }
    *(void**)&lbl_8052C9B8[0x340] = arg0;
    lbl_8052C9B8[0x400] = 1;
    return 0;
}
