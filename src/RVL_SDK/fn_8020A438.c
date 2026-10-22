#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
typedef struct Blk {
    int unk0;
    int unk4;
    char pad[0xC8];
    int unkD0;
    char pad2[0x40];
    int unk114;
} Blk;
extern Blk lbl_804ECE00[];

int fn_8020A438(int arg0, Blk** arg1) {
    int r;
    int en;
    Blk* b = &lbl_804ECE00[arg0];
    if (arg0 < 0 || arg0 >= 2 || b->unk114 == 0) {
        return -0x80;
    }
    en = OSDisableInterrupts();
    if (b->unk0 == 0) {
        r = -3;
    } else if (b->unk4 == -1) {
        r = -1;
    } else {
        r = 0;
        b->unk4 = -1;
        b->unkD0 = 0;
        *arg1 = b;
    }
    OSRestoreInterrupts(en);
    return r;
}
