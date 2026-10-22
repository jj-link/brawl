#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    unsigned char unk0[4];
    u16 flags;
    unsigned char unk6[2];
    unsigned char records[10][0x4A];
} Entry;

typedef struct {
    Entry *entries[4];
    int active[4];
} Context;

extern Context *fn_803CD3D8(void);
extern int fn_803D521C(void *);
extern void fn_803D4FC4(void *, void *);

int fn_803D577C(void *arg0, int arg1, u32 arg2, int arg3)
{
    Context *ctx;
    Entry *entry;
    u16 mask;

    if (arg1 < 0 || arg1 >= 4) return 0;
    if (arg2 >= 10) return 0;

    ctx = fn_803CD3D8();
    if (ctx == 0) return 0;
    if (ctx->active[arg1] == 0) return 0;

    entry = ctx->entries[arg1];
    mask = (u16)(1 << arg2);

    if (fn_803D521C(entry->records[arg2] + 0x18) == 0) return 0;
    if (arg3 == 0 && (entry->flags & mask)) return 0;

    fn_803D4FC4(entry->records[arg2], arg0);
    return 1;
}
