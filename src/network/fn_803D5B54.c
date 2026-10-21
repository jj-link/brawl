#pragma force_active on
extern char lbl_8041AEC0[];

void *fn_803D5B54(unsigned int arg0) {
    if (arg0 >= 6) {
        return 0;
    }
    return lbl_8041AEC0 + arg0 * 0x4A;
}
