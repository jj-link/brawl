#pragma force_active on
extern void fn_802464CC(int);
extern void fn_80246540(int);
extern char lbl_80529CF8[];

void fn_80240634(void) {
    if (*(unsigned char*)(lbl_80529CF8 + 0x1978) == 3) {
        fn_802464CC(1);
        fn_80246540(1);
    }
}
