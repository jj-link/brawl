#pragma force_active on
extern char lbl_80529CF8[];

int fn_802393A0(int arg0) {
    if (arg0 == 0) {
        *(int*)(lbl_80529CF8 + 0x4C8) = 0;
    } else {
        if (*(int*)(lbl_80529CF8 + 0x4C8) != 0) {
            return 2;
        }
        *(int*)(lbl_80529CF8 + 0x4C8) = arg0;
    }
    return 0;
}
