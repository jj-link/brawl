#pragma force_active on
extern char lbl_80529CF8[];

int fn_8023B444(int arg0) {
    int old = *(int*)(lbl_80529CF8 + 0x568);
    *(int*)(lbl_80529CF8 + 0x568) = arg0;
    return old;
}
