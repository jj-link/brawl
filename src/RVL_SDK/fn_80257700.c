#pragma force_active on
typedef unsigned char u8;

extern u8 lbl_8052D9C0[];

u8 fn_80257700(u8 arg0) {
    if (arg0 != 0xFF) {
        lbl_8052D9C0[0x4630] = arg0;
    }
    return lbl_8052D9C0[0x4630];
}
