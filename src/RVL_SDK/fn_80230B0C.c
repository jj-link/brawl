#pragma force_active on
extern unsigned char lbl_80525F28[0x38];

void fn_80230B0C(unsigned char arg0, unsigned char arg1, unsigned short arg2) {
    lbl_80525F28[0x1E] = 0;
    lbl_80525F28[0x1A] = 0;
    lbl_80525F28[0x1B] = 0;
    lbl_80525F28[0x1C] = 0;
    lbl_80525F28[0x1F] = arg0;
    lbl_80525F28[0x20] = arg1;
    *(unsigned short*)(lbl_80525F28 + 0x12) = arg2;
}
