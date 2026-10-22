#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern int fn_80367F78(int, int, int, int, void *, int);
extern void fn_80338128(void);
extern const char lbl_804894E8[];
extern const char lbl_80489508[];
extern int *lbl_805A0F70;

void fn_80336FAC(int arg0, int *arg1) {
    fn_80335638(0x20000, lbl_804894E8, *arg1);
    if (lbl_805A0F70[7] != 0) {
        fn_80335638(0x20000, lbl_80489508);
        fn_80367F78(arg0, *arg1, 0, 0, fn_80338128, 0);
    }
}
