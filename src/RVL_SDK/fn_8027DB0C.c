#pragma force_active on

extern void fn_8027DB2C(int, int);

void fn_8027DB0C(int unused, int arg1) {
    int limit = arg1 * 4 - arg1;
    arg1 = 4;
    while (arg1 < limit) {
        arg1 <<= 1;
    }
    fn_8027DB2C(unused, arg1);
}
