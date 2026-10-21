#pragma force_active on
extern "C" {

extern unsigned short lbl_8042D180[];
extern int lbl_8059CE40;

int fn_800567D8(int arg0) {
    int r4 = -1;
    if (arg0 >= 0 && arg0 < lbl_8059CE40) {
        r4 = (lbl_8042D180[arg0] >> 6) & 0x3FF;
    }
    return r4;
}

}
