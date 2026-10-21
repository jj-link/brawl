#pragma force_active on
extern "C" {
int fn_80298198(int *arg0, int arg1) {
    int temp_r3 = arg0[2];
    return arg1 + (((temp_r3 * 4) - temp_r3) * 0x30);
}
}
