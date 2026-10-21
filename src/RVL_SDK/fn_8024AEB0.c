#pragma force_active on
extern unsigned char lbl_8052CDC0[];

unsigned char fn_8024AEB0(unsigned char arg) {
    if (arg != 0xFF)
        lbl_8052CDC0[0] = arg;
    return lbl_8052CDC0[0];
}
