#pragma force_active on
extern char lbl_80529CF8[];

int fn_8023F234(unsigned int arg0) {
    char *p = lbl_80529CF8;
    if (arg0 == *(unsigned short *)(p + 0x185E) && *(unsigned short *)(p + 0x185C) == 4) {
        return 1;
    }
    if (arg0 == *(unsigned short *)(p + 0x1892) && *(unsigned short *)(p + 0x1890) == 4) {
        return 1;
    }
    if (arg0 == *(unsigned short *)(p + 0x18C6) && *(unsigned short *)(p + 0x18C4) == 4) {
        return 1;
    }
    return 0;
}