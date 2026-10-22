#pragma force_active on
extern char lbl_80529994[];
extern int lbl_805A3A70;
extern int lbl_805A3A78;
extern void *memset(void *s, int c, unsigned long n);
extern void fn_80230450(void);
extern void fn_80230454(void);
extern void fn_802324CC(int arg0, int arg1);
extern void fn_802324E0(void *arg);
extern void *fn_8022EE58(unsigned short size);

int fn_80234B00(int arg0) {
    short *temp_r3;

    memset(lbl_80529994, 0, 0x104);
    fn_80230450();
    fn_802324CC(1, (int)&lbl_805A3A70);
    fn_802324CC(2, (int)&lbl_805A3A78);
    fn_80230454();
    temp_r3 = (short *)fn_8022EE58(0xC);
    if (temp_r3 != 0) {
        temp_r3[0] = 0x100;
        *(int *)((char *)temp_r3 + 8) = arg0;
        fn_802324E0(temp_r3);
        return 0;
    }
    return 1;
}
