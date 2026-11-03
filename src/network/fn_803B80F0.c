#pragma force_active on
int fn_803AA334(char *);

int fn_803B80F0(char *arg0) {
    unsigned short temp_r4;
    int var_r5;

    var_r5 = 0;
    if (*(int *)(arg0 + 0x1C) != 2) {
        return 0xC;
    }
    temp_r4 = *(unsigned short *)(arg0 + 0x187C);
    if (!(temp_r4 & 2)) {
        return 0x24;
    }
    if (temp_r4 & 4) {
        var_r5 = fn_803AA334(arg0);
    }
    return var_r5;
}
