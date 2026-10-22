#pragma force_active on
int fn_80335238(void);
int DWC_GetState(void);
void fn_803484C0(void);
void fn_80335638(int, const char *, ...);
extern int lbl_805A0FA8;
extern char lbl_8048AAA0[];

int fn_8033C0F0(void) {
    int var_r0;

    if (fn_80335238() != 0) {
        var_r0 = 0;
    } else if (lbl_805A0FA8 == 0 || DWC_GetState() != 5 || *(unsigned char *)(lbl_805A0FA8 + 0x1BD) != 0) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
    }
    if (var_r0 != 0) {
        fn_803484C0();
        return 1;
    }
    fn_80335638(4, lbl_8048AAA0);
    return 0;
}
