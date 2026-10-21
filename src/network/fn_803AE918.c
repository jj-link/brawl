#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Context {
    u8 pad[0x20];
    u8 shift;
} Context;

typedef struct Entry {
    u16 flags;
    u16 pad2;
    u32 start;
    u32 pad8;
    u32 first;
    u32 last;
    u32 pad14;
    u32 base;
} Entry;

extern s32 fn_803AAA04(Context *, u32, u32, u32, u32 *);
extern s32 fn_803B6FBC(Context *, u32, u32, u32);

s32 fn_803AE918(Context *ctx, Entry *entry)
{
    u32 done;
    u32 first;
    u32 count;
    u32 base;
    s32 result;

    if (entry != 0 && (entry->flags & 2)) {
        if (entry->base != 0xFFFFFFFFU) {
            first = entry->first;
            base = entry->base + ((first - entry->start) >> ctx->shift);
            count = (entry->last >> ctx->shift) - (first >> ctx->shift) + 1;
            result = fn_803AAA04(ctx, first, base, count, &done);
            if (result != 0) return result;
            if (done != count) return 0x11;
            if (entry->flags & 4) {
                result = fn_803B6FBC(ctx, first, base, count);
                if (result != 0) return result;
            }
            entry->first = 0;
            entry->last = 0;
            entry->flags &= ~2;
        }
    }
    return 0;
}
