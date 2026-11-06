#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern int lbl_804F6810[];

void fn_8021AC3C(int arg0) {
    unsigned char *base;
    unsigned char *obj;
    unsigned short v;
    int level;
    int t;

    base = (unsigned char *)lbl_804F6810[arg0];
    level = OSDisableInterrupts();
    obj = base + (unsigned char)(base[0x8c8] == 0) * 0x60;
    v = *(unsigned short *)(obj + 0xa0);
    if ((v & 3) == 3) {
        *(unsigned short *)(obj + 0xa0) = v & ~2;
    }
    v = *(unsigned short *)(obj + 0xa0);
    if ((v & 0xc) == 0xc) {
        *(unsigned short *)(obj + 0xa0) = v & ~4;
    }
    t = *(int *)(base + 0x8b8);
    if ((unsigned int)(t - 6) <= 2) {
        v = *(unsigned short *)(obj + 0xca);
        if ((v & 0x8002) == 0x8002) {
            *(unsigned short *)(obj + 0xca) = v & 0x7fff;
        }
        v = *(unsigned short *)(obj + 0xca);
        if ((v & 0x4001) == 0x4001) {
            *(unsigned short *)(obj + 0xca) = v & ~0x4000;
        }
    }
    OSRestoreInterrupts(level);
}
