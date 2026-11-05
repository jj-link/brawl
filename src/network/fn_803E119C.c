#pragma force_active on
typedef unsigned int u32;
typedef struct Info { char pad0[0x10]; u32 value; char pad14[8]; u32 count; char pad20[0x14]; u32 limit; } Info;
typedef struct Record { int key; u32 value; int owner; } Record;
typedef struct Context { int owner; char pad4[4]; int *state; char padc[0x10]; int flag; char pad20[0x10]; Record *record; Info *info; } Context;
extern int fn_803E0A88(Context *, int, int, int, u32 *, u32 *);
int fn_803E119C(Context *ctx, int key, int arg2, u32 *out) {
    u32 value, other;
    Info *info = ctx->info;
    u32 count = info->count;
    Record *record = ctx->record;
    int result;
    if ((u32)*ctx->state == 1) {
        if (count <= 1) { *out = -1; return 0; }
        *ctx->state = info->value;
    }
    *out = -1;
    result = fn_803E0A88(ctx, key, 2, arg2, &other, &value);
    switch (result) {
    case 0:
        if (other >= 2 && other < ctx->info->limit + 2) *out = other;
        result = 0;
        break;
    default:
        break;
    }
    if (result != 0) return result;
    if (*out == 0xFFFFFFFF) return 0;
    record->owner = ctx->owner;
    record->key = key;
    record->value = *out;
    return 0;
}