#pragma force_active on
void fn_8027DFFC(int, int, int *);

int fn_8027E074(int arg0, int arg1, int arg2) {
    int sp8;

    sp8 = arg2;
    fn_8027DFFC(arg0, arg1, &sp8);
    return sp8;
}
