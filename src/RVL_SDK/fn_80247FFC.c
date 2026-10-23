#pragma force_active on
#pragma global_optimizer off

extern void fn_80232020(void *);
extern int fn_8024841C(unsigned int);
extern unsigned char lbl_8052C9B8[0x408];

int fn_80247FFC(unsigned int arg0) {
    unsigned char *base;
    unsigned char *entry;
    int offset;

    base = lbl_8052C9B8;
    if (base[0x400] == 0) {
        return 1;
    }
    if ((arg0 > 0x10) ||
        (offset = arg0 * 0x34, entry = base + offset, base[offset] == 0)) {
        return 5;
    }
    entry[0xC] = 1;
    fn_80232020(entry + 0x1C);
    if (base[offset + 0xA] != 1) {
        return 4;
    }
    entry[0xC] = 1;
    return fn_8024841C(arg0);
}
