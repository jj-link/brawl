#pragma force_active on
extern unsigned short lbl_8042D180[544];
extern unsigned short lbl_8042DBC0[];
extern int lbl_8059CE40;

extern "C" unsigned short fn_800562A4(short arg0) {
    const int count = lbl_8059CE40;
    unsigned short* p = lbl_8042D180;
    unsigned short result = 9;
    int i = 0;
    for (int remaining = count; remaining > 0; --remaining) {
        if (arg0 == (unsigned int)((p[i] & 0xFFC0) >> 6)) {
            result = (lbl_8042D180[i] >> 2) & 0xF;
            break;
        }
        ++i;
    }
    return lbl_8042DBC0[result];
}