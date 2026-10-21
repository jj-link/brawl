#pragma force_active on
extern char lbl_80599F78[];

char* TRKGetBuffer(int arg0) {
    char* var_r0 = 0;
    if (arg0 >= 0 && arg0 < 3) {
        var_r0 = lbl_80599F78 + arg0 * 0x890;
    }
    return var_r0;
}
