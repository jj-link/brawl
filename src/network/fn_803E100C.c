#pragma force_active on
typedef unsigned int u32;
typedef struct Info {
    char pad0[0x10];
    u32 value;
    char pad14[8];
    u32 count;
    char pad20[0x14];
    u32 limit;
} Info;
typedef struct Record { int key; u32 value; int owner; } Record;
typedef struct Context {
    int owner;
    char pad4[4];
    int *state;
    char padc[0x10];
    int flag;
    char pad20[0x10];
    Record *record;
    Info *info;
} Context;
extern int fn_803DFC24(Context *, int, u32 *, u32 *);
extern int fn_803E0A88(Context *, int, int, int, u32 *, u32 *);
static inline int helper(Context *ctx, int key, int mode, u32 *out) {
    u32 other, value;
    int result;
    *out = -1;
    result = fn_803E0A88(ctx, key, mode != 0, 0, &other, &value);
    if (result != 0) return result;
    if (value >= 2 && value < ctx->info->limit + 2) *out = value;
    return 0;
}
int fn_803E100C(Context *ctx, int key, int mode, u32 *out) {
    u32 status;
    int result;
    int *state = ctx->state;
    Info *info = ctx->info;
    u32 count = info->count;
    Record *record = ctx->record;
    if (*state == 0 && mode == 0) {
        *out = -1;
        return 0;
    }
    if ((u32)*state == 1) {
        if (count <= 1) {
            *out = -1;
            return 0;
        }
        *state = info->value;
    }
    if (ctx->flag != 0 && mode == 0) {
        result = fn_803DFC24(ctx, key, out, &status);
        if (result != 0) return result;
        if (status == 1) {
            record->owner = ctx->owner;
            record->key = key;
            record->value = *out;
            return 0;
        }
    }
    result = helper(ctx, key, mode, out);
    if (result != 0) return result;
    if (*out == 0xffffffff) return 0;
    record->owner = ctx->owner;
    record->key = key;
    record->value = *out;
    return 0;
}