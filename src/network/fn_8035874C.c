#pragma force_active on
extern void fn_80352260(int, void *, void *);
extern void fn_80335390(void);
extern void fn_80335450(void);
extern int lbl_805A1030;

void fn_8035874C(int arg0, int arg1) {
    lbl_805A1030 = arg1;
    fn_80352260(arg0, fn_80335390, fn_80335450);
}
