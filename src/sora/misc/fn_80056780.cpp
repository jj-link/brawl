#pragma force_active on
extern "C" {
extern unsigned short lbl_8042D180[];
extern int lbl_8059CE40;

int fn_80056780(int arg0) {
    if (arg0 < 0) return -1;
    unsigned short i = 0;
    while (i < lbl_8059CE40) {
        if (arg0 == ((lbl_8042D180[i] >> 6) & 0x3FF))
            return i;
        i++;
    }
    return -1;
}
}
