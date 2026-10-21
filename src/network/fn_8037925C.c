#pragma force_active on
typedef unsigned char u8;

int fn_8037925C(u8 *arg0, int arg1) {
    int temp_r5;

    temp_r5 = *(int *)(arg0 + 0x100);
    if (temp_r5 >= 0xFE) {
        return 0;
    }
    if (arg1 < 1 || arg1 > 0xFE) {
        return 0;
    }
    arg0[temp_r5] = (u8)arg1;
    *(int *)(arg0 + 0x100) = temp_r5 + 1;
    return 1;
}
