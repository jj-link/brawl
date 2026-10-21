#pragma force_active on
extern char lbl_80529CF8[];

int fn_8023B5C4(int arg0) {
    if (*(int*)(lbl_80529CF8 + 0x56C) != 0 && arg0 != 0) {
        return 2;
    }
    *(int*)(lbl_80529CF8 + 0x56C) = arg0;
    return 0;
}
