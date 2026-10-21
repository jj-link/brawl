#pragma force_active on
int fn_803AF38C(int, int, int, int);

int fn_803B000C(int arg0, int arg1) {
    int temp_r3;

    temp_r3 = fn_803AF38C(arg0, arg0 + 0x15F4, arg1, 0);
    return temp_r3 & ((-temp_r3 | temp_r3) >> 0x1F);
}
