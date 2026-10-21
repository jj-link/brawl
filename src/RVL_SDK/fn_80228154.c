#pragma force_active on

extern unsigned char lbl_804F9FC0[];

void fn_80228154(int arg0) {
    int offset = arg0 * 0x528;
    ((unsigned char *)lbl_804F9FC0 + offset)[0x520] = 1;
}
