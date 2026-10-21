#pragma force_active on

typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} LblEntry;

extern s32 fn_803C43AC(void);
extern LblEntry lbl_80563590[];

s32 fn_803C7E40(void) {
    LblEntry *p;
    u32 idx = (u32)fn_803C43AC();

    if (idx < 0x1AU) {
        p = &lbl_80563590[idx];
    } else {
        p = (LblEntry *)0;
    }
    if (p != (LblEntry *)0) {
        return p->unkC;
    }
    return 0;
}
