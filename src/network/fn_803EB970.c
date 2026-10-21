#pragma force_active on
extern int PFSTR_InitStr(void *, int, int);
extern int fn_803DC288(void *, int *);
extern void fn_803EB4EC(int, int);
extern int lbl_805644C0[];

void fn_803EB970(int arg0) {
    char sp10[0x10];
    int sp8;
    int temp_r3;

    temp_r3 = PFSTR_InitStr(sp10, arg0, 1);
    if (temp_r3 == 0) {
        temp_r3 = fn_803DC288(sp10, &sp8);
    } else {
        lbl_805644C0[0x10] = temp_r3;
    }
    fn_803EB4EC(temp_r3, sp8);
}
