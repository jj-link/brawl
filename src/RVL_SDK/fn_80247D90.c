#pragma force_active on
#pragma global_optimizer off
extern void fn_80232020(void *);
extern int fn_8024841C(unsigned int);
extern unsigned char lbl_8052C9B8[0x408];
int fn_80247D90(unsigned int arg0) {
    unsigned char *base;
    unsigned char *entry;
    unsigned char *p;
    int offset;
    base = lbl_8052C9B8;
    if (base[0x400] == 0) return 1;
    if ((arg0 > 0x10) ||
        (offset = arg0 * 0x34, entry = base + offset, base[offset] == 0)) return 5;
    if (base[0x400] != 0 && arg0 <= 0x10 && base[offset] != 0) {
        entry[0xC] = 1;
        fn_80232020(entry + 0x1C);
        if (base[offset + 0xA] == 1) {
            entry[0xC] = 1;
            fn_8024841C(arg0);
        }
    }
    entry[0] = 0;
    p = lbl_8052C9B8 + offset;
    p[0x10] = 0;
    *(unsigned short *)(p + 0x16) = 0;
    *(unsigned short *)(p + 0x14) = 0;
    return 0;
}