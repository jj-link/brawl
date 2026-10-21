#pragma force_active on
extern char lbl_80529CF8[];

void fn_8023B310(unsigned char *arg0) {
    if (arg0[0] == 0) {
        lbl_80529CF8[0x635] = arg0[1];
        lbl_80529CF8[0x634] = arg0[2];
        lbl_80529CF8[0x633] = arg0[3];
        lbl_80529CF8[0x632] = arg0[4];
        lbl_80529CF8[0x631] = arg0[5];
        lbl_80529CF8[0x630] = arg0[6];
    }
}
