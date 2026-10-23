#pragma force_active on
typedef signed char s8;

extern void fn_801EA4E4(int, s8 *, int);
extern void fn_801EA098(int);
extern int lbl_805A0868;

void fn_801EBCE4(void) {
    s8 sp8[2];

    lbl_805A0868 = 3;
    sp8[0] = 1;
    sp8[1] = 3;
    fn_801EA4E4(0xE0, sp8, 2);
    fn_801EA098(2);
}
