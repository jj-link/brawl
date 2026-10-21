#pragma force_active on

typedef unsigned int u32;
typedef int s32;

typedef struct LblEntry {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unk12;
    s32 unk16;
} LblEntry;

extern u32 fn_803C43AC(void);
extern LblEntry lbl_80563590[];

s32 fn_803C7D10(void) {
    LblEntry *p;
    u32 idx;

    idx = fn_803C43AC();
    if (idx < 0x1A) {
        p = &lbl_80563590[idx];
    } else {
        p = 0;
    }
    if (p != 0) {
        return p->unk4;
    }
    return 0;
}
