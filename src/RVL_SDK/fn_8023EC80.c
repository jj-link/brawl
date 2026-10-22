#pragma force_active on
extern unsigned char fn_80244B64(unsigned short, int);
extern char lbl_80529CF8[];

int fn_8023EC80(unsigned int arg0) {
    char *base = lbl_80529CF8 + arg0 * 0x34;
    unsigned short t;

    if (arg0 >= 3 || (t = *(unsigned short *)(base + 0x185C)) == 0) {
        return 7;
    }
    if (*(unsigned short *)(base + 0x185E) == 0xFFFF || t == 6) {
        *(unsigned short *)(base + 0x185E) = 0xFFFF;
        *(unsigned short *)(base + 0x185C) = 0;
        *(unsigned int *)(base + 0x1864) = 0;
        return 0;
    }
    *(unsigned short *)(base + 0x185C) = 5;
    if (fn_80244B64(*(unsigned short *)(base + 0x185E), 0x13) == 0) {
        *(unsigned short *)(base + 0x185C) = t;
        return 3;
    }
    return 1;
}
