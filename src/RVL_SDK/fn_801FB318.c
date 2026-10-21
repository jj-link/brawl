#pragma force_active on

extern int fn_801E187C(void *);
extern int lbl_805A08D8;
extern int lbl_805A091C;

int fn_801FB318(void) {
    lbl_805A091C = 1;
    return fn_801E187C(&lbl_805A08D8);
}
