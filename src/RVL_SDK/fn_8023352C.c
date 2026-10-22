#pragma force_active on

extern void fn_80233970(void);
extern void fn_802324FC(void *, int, int);
extern void fn_802335B4(void);
extern unsigned char lbl_80529918[];

void fn_8023352C(void *arg0) {
    char *self = (char *)arg0;
    if (*(int *)(self + 0x108) != 0) {
        ((void (*)(int, void *))((int *)lbl_80529918)[0])(2, self + 8);
    }
    if (lbl_80529918[0x78] == 0) {
        lbl_80529918[0x78] = 0;
        fn_80233970();
        return;
    }
    lbl_80529918[0x79] = 1;
    ((int *)lbl_80529918)[0x12] = (int)&fn_802335B4;
    fn_802324FC(lbl_80529918 + 0x40, 0, 0xbb8);
}
