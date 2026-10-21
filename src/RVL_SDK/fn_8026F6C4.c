#pragma force_active on
extern void fn_802711AC(int, int);
extern int lbl_805A0E80;

int fn_8026F6C4(int arg0) {
    fn_802711AC(lbl_805A0E80, arg0);
    if (*(int *)(lbl_805A0E80 + 0x10) != 0x12) {
        return -1;
    }
    return *(int *)(lbl_805A0E80 + 0xB0);
}
