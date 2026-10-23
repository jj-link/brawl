#pragma force_active on
extern char lbl_8041AD60[];

int fn_803D0624(unsigned short *arg0) {
    return *(int*)(lbl_8041AD60 + ((*arg0 >> 8) & 0x1C));
}
