#pragma force_active on
extern void fn_802326A0(void *a, int b, int c, int d, void *e);
extern char lbl_80529858[];

void fn_802324FC(int arg0, int arg1, int arg2) {
    fn_802326A0(lbl_80529858 + 0x68, arg0, arg1, arg2, lbl_80529858);
}
