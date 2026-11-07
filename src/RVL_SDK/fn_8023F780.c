#pragma force_active on
extern void fn_80232020(void *);
extern void *fn_8023A0F0(int);
extern void fn_80244F74(int, int, int);
extern void fn_80245158(int);
extern void *memset(void *, int, unsigned long);
extern char lbl_80529CF8[];

void fn_8023F780(int arg0, int arg1, int arg2, int arg3, int *arg4) {
    void *temp_r3;

    if (*(int *)(lbl_80529CF8 + 0x194C) != 0) {
        fn_80232020(lbl_80529CF8 + 0x193C);
        *(int *)(lbl_80529CF8 + 0x194C) = 0;
        memset(lbl_80529CF8 + 0x1954, 0xFF, 6);
        if (arg1 != 0) {
            *(unsigned char *)(lbl_80529CF8 + 0x27BF) = 0xE;
            fn_80245158(arg0);
            return;
        }
        *(unsigned char *)(lbl_80529CF8 + 0x27BF) = 0;
        fn_80244F74(arg0, arg2, arg3);
        temp_r3 = fn_8023A0F0(arg0);
        if (temp_r3 != 0) {
            ((int *)temp_r3)[4] = arg4[0];
            ((int *)temp_r3)[5] = arg4[1];
        }
    }
}
