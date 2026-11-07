#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_80343118(int, int, int);
extern int fn_8034A500(void);
extern char lbl_8048CC38[];
extern char lbl_8048BE08[];
extern int lbl_805A0FA8;

void fn_8034C6E0(int arg0)
{
    int state;
    int *p;
    fn_80335638(0x40, lbl_8048CC38, arg0);
    state = *(int *)(lbl_805A0FA8 + 0x1b4);
    if (state == 1) {
        *(int *)(lbl_805A0FA8 + 0x1b4) = 5;
    } else if (state != 5 && state != 16) {
        fn_80335638(0x40, lbl_8048BE08);
        return;
    }
    if (arg0 == *(int *)(lbl_805A0FA8 + 0x194)) {
        (*(unsigned char *)(lbl_805A0FA8 + 0x190))++;
    } else {
        *(unsigned char *)(lbl_805A0FA8 + 0x190) = 0;
        *(int *)(lbl_805A0FA8 + 0x194) = arg0;
    }
    p = (int *)lbl_805A0FA8;
    p[0x19c / 4] = 0;
    p[0x198 / 4] = 0;
    fn_80343118(1, arg0, 0);
    if (fn_8034A500() == 0) {
        *(unsigned char *)(lbl_805A0FA8 + 0x3e8) = 0xff;
    }
}