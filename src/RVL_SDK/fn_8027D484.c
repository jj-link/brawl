#pragma force_active on
extern void fn_8027D4A4(int a, int b);

void fn_8027D484(int unused, int arg1) {
    int limit = arg1 * 4 - arg1;
    arg1 = 4;
    while (arg1 < limit) {
        arg1 <<= 1;
    }
    fn_8027D4A4(unused, arg1);
}
