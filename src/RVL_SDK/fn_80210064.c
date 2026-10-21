#pragma force_active on
extern int fn_8020F3F0(int*, int);

int fn_80210064(void) {
    int sp8;
    if (fn_8020F3F0(&sp8, 0x14) == 0) {
        sp8 = 0;
    }
    return sp8;
}
