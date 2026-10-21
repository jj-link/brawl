#pragma force_active on
int fn_803D9C50(int a, int b, int c, int d);

int fn_803DA71C(int arg0, int arg1) {
    int temp_r3;

    temp_r3 = fn_803D9C50(arg0, arg0 + 0x1630, arg1, 0);
    return temp_r3 & ((-temp_r3 | temp_r3) >> 31);
}
