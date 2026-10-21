#pragma force_active on
int fn_8037EEE8(int);

int fn_80362348(int *arg0) {
    if (arg0[0x30 / 4] != 0) {
        return 4;
    }
    fn_8037EEE8(arg0[0x28 / 4]);
    return 1;
}
