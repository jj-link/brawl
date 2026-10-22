#pragma force_active on
extern unsigned char lbl_8052C9B8[0x408];
extern unsigned char lbl_8040D9C0[0x28];
extern unsigned char lbl_80482490[0x20];
extern unsigned char lbl_804824B0[0x22];

unsigned char fn_8024A304(int, void *);
void fn_8024A4A0(int);
void fn_802319E4(int id, const char *msg);

int fn_802482C4(void) {
    unsigned char *b = lbl_8052C9B8;
    b[0x346] = 1;
    *(unsigned short *)(b + 0x348) = 0x280;
    b[0x364] = 1;
    *(unsigned short *)(b + 0x366) = 0xFFFF;
    if (fn_8024A304(0x11, lbl_8040D9C0) == 0) {
        if (b[0x401] >= 1) {
            fn_802319E4(0x1E0000, (const char *)lbl_80482490);
        }
        return 0xE;
    }
    if (fn_8024A304(0x13, lbl_8040D9C0) == 0) {
        fn_8024A4A0(0x11);
        if (b[0x401] >= 1) {
            fn_802319E4(0x1E0000, (const char *)lbl_804824B0);
        }
        return 0xE;
    }
    b[0x000] = 0;
    b[0x010] = 0;
    b[0x034] = 0;
    b[0x044] = 0;
    b[0x068] = 0;
    b[0x078] = 0;
    b[0x09C] = 0;
    b[0x0AC] = 0;
    b[0x0D0] = 0;
    b[0x0E0] = 0;
    b[0x104] = 0;
    b[0x114] = 0;
    b[0x138] = 0;
    b[0x148] = 0;
    b[0x16C] = 0;
    b[0x17C] = 0;
    b[0x1A0] = 0;
    b[0x1B0] = 0;
    b[0x1D4] = 0;
    b[0x1E4] = 0;
    b[0x208] = 0;
    b[0x218] = 0;
    b[0x23C] = 0;
    b[0x24C] = 0;
    b[0x270] = 0;
    b[0x280] = 0;
    b[0x2A4] = 0;
    b[0x2B4] = 0;
    b[0x2D8] = 0;
    b[0x2E8] = 0;
    b[0x30C] = 0;
    b[0x31C] = 0;
    return 0;
}
