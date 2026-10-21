#pragma force_active on
int fn_803E12B4(int a, int b, int c, int d, int e);

int fn_803E1458(int a, int b, int c, int d) {
    int temp_r3;

    temp_r3 = fn_803E12B4(a, b, 2, c, d);
    return temp_r3 & ((-temp_r3 | temp_r3) >> 31);
}
