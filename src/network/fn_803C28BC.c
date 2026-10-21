#pragma force_active on
extern int lbl_80492730[];

int fn_803C28BC(int arg0) {
    if (arg0 == 0)
        return 0;
    if (arg0 == -1)
        return -1;
    if (arg0 > 0 && arg0 < 0xA0)
        return lbl_80492730[arg0];
    if (arg0 == 0x1000)
        return 5;
    return arg0;
}
