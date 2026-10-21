#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

typedef struct Table {
    s32 unk0;
    char *unk4;
    s32 unk8;
    u32 unkC;
} Table;

typedef struct Out {
    Table *unk0;
    s32 unk4;
    s32 unk8;
} Out;

s32 fn_80210A4C(Table *arg0, s32 arg1, Out *arg2) {
    char *base = arg0->unk4;
    char *e;

    if (arg1 < 0 || (u32)arg1 >= arg0->unkC ||
        ((*(u32 *)(base + (arg1 *= 12)) & 0xFF000000) != 0)) {
        return 0;
    }

    arg2->unk0 = arg0;
    e = base + arg1;
    arg2->unk4 = *(s32 *)(e + 4);
    arg2->unk8 = *(s32 *)(e + 8);
    return 1;
}
