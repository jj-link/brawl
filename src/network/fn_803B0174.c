#include <types.h>
#pragma force_active on

typedef struct Entry {
    u16 flags;
    u8 pad02[0x16];
    u32 base;
    u32 tag;
    struct Entry *prev;
    struct Entry *next;
} Entry;

typedef struct Context {
    u8 pad00[0x15E8];
    u32 flags;
    u8 pad15EC[0xC];
    Entry *head;
} Context;

extern s32 fn_803AE918(Context *, Entry *);
extern s32 fn_803C7F98(Context *, s32);

s32 fn_803B0174(Context *ctx, u32 tag)
{
    s32 result;
    Entry *head;
    Entry *entry;
    s32 currentDirty;
    s32 dirty;

    result = 0;
    dirty = 0;

    if (ctx->flags & 7) {
        head = ctx->head;
        if (head->tag == 0 || head->tag == tag) {
            if (head != 0 && (head->flags & 2) && head->base != 0xFFFFFFFFU) {
                dirty = 1;
            }
            result = fn_803AE918(ctx, head);
            if (result != 0) {
                return result;
            }
        }
        for (entry = head->prev; entry != head; entry = entry->prev) {
            if (entry->tag == 0 || entry->tag == tag) {
                currentDirty = 0;
                if (entry != 0 && (entry->flags & 2) && entry->base != 0xFFFFFFFFU) {
                    currentDirty = 1;
                }
                result = fn_803AE918(ctx, entry);
                if (result != 0) {
                    if (dirty != 0) {
                        fn_803C7F98(ctx, 0);
                    }
                    return result;
                }
                if (currentDirty != 0) {
                    dirty = 1;
                }
            }
        }
        if (dirty != 0 && fn_803C7F98(ctx, 1) != 0) {
            return 0x11;
        }
    }
    return result;
}
