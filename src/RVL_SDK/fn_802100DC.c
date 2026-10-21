#pragma force_active on
extern int fn_8020F3F0(int *p, int v);

int fn_802100DC(void) {
    int sp8;

    if (fn_8020F3F0(&sp8, 0x17) == 0) {
        sp8 = 0;
    }
    return sp8;
}
