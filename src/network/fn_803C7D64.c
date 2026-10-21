#pragma force_active on

typedef struct LblEntry {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
} LblEntry;

extern unsigned int fn_803C43AC(void);
extern LblEntry lbl_80563590[];

void fn_803C7D64(void *unused, int value) {
    unsigned int idx;
    LblEntry *p;

    idx = fn_803C43AC();
    if (idx < 0x1A) {
        p = &lbl_80563590[idx];
    } else {
        p = 0;
    }
    if (p != 0) {
        p->unk4 = value;
    }
}
