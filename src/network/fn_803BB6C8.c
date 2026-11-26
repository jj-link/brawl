#include <types.h>
#pragma force_active on

typedef struct Info {
    u16 size;
    u8 pad[0x1E];
    u8 shift;
} Info;

typedef struct Owner {
    u32 flags;
    u8 pad04[0x1C];
    s32 f20;
    u8 pad24[0x240];
    u32 f264;
    Info *info;
    u8 pad26C[0x20];
    u16 f28C;
} Owner;

typedef struct Slot {
    u32 inUse;
    u32 arg2;
    Owner *owner;
    u8 pad0C[0xC];
    u32 f18;
    u32 f1C;
    s32 f20;
    u32 f24;
    u16 f28;
    u8 pad2A[2];
    u16 f2C;
    u8 pad2E[2];
} Slot;

typedef struct Ctx {
    u8 pad0[0x21C];
    u8 flags;
    u8 pad21D[5];
    u16 f222;
    u16 f224;
    u16 f226;
    s32 f228;
    void *mgr;
    u32 f230;
    u32 f234;
    u8 pad238[8];
} Ctx;

extern s32 fn_803B5638(void *, void *, void *, s32, s32);
extern s32 fn_803BE3C8(s32, void *, void *);
extern u16 fn_803A9C74(void *, s32);
extern u32 fn_803A9A78(void *);
extern void *fn_803A9AA8(void *, u32);
extern void fn_803BEE24(void *, void *);
extern void fn_803A9A80(void *, void *);
extern s32 fn_803B847C(void *, void *, void *, void *);
extern s32 fn_803B3268(void *, void *, s32, void *, s32, s32);
extern void fn_803B3BA8(void *, void *);
extern Owner *fn_803BB1E4(void *, void *);
extern s32 fn_803BB3B4(void *, void *, void *, u16);
extern s32 fn_803BBFF8(void *, void *);
extern void fn_803B7780(void *, u32, s32, s32);
extern void fn_803B814C(void *);

static int has_entry(void *p, int *entry) {
    *entry = 0;
    if (p == 0) return 0;
    fn_803BBFF8(p, entry);
    return *entry != 0;
}

static Info *get_info(Slot *slot) {
    if (slot == 0) return 0;
    return slot->owner->info;
}

static void seek_zero(Slot *slot, u32 pos) {
    Info *info = get_info(slot);
    u8 shift = info->shift;
    u32 mask = info->size - 1;
    u32 old = slot->f1C;
    if ((old >> shift) + ((old & mask) != 0) !=
        (pos >> shift) + ((pos & mask) != 0)) {
        slot->f20 = -1;
    }
    slot->f1C = pos;
    info = get_info(slot);
    slot->f24 = slot->f1C >> info->shift;
    slot->f28 = slot->f1C & (info->size - 1);
}

static inline u32 block_count(Info *info, u32 pos) {
    return (pos >> info->shift) + ((pos & (info->size - 1)) ? 1 : 0);
}

static void seek_slot(Slot *slot, u32 pos) {
    Info *info = get_info(slot);
    u32 before = block_count(info, slot->f1C);
    u32 after = block_count(info, pos);
    if (before != after) {
        slot->f20 = -1;
    }
    slot->f1C = pos;
    info = get_info(slot);
    slot->f24 = slot->f1C >> info->shift;
    slot->f28 = slot->f1C & (info->size - 1);
}

s32 fn_803BB6C8(void *arg0, s32 arg1, s32 arg2, void **arg3) {
    Ctx ctx;
    u8 spE8[0x200];
    u8 req[0x70];
    u8 sp40[0x38];
    u8 sp30[0x10];
    u8 sp20[0x10];
    u8 sp10[0x10];
    int spC;
    u32 sp8;
    s32 n;
    s32 r;
    s32 temp;
    void *mgr;
    Owner *owner;
    Slot *slot;
    s32 i;
    Ctx *scan;

    *arg3 = NULL;
    r = fn_803B5638(req, &ctx, arg0, arg1, 1);
    if (r != 0) return r;
    if (!(ctx.flags & 0x10)) return 1;
    if (fn_803BE3C8(arg1, sp20, sp30) != 0) return 1;
    n = fn_803A9C74(sp30, 1);
    if (n > 0xFF) return 1;
    if (fn_803A9A78(sp30) == 2)
        fn_803BEE24(spE8, fn_803A9AA8(sp30, 1));
    fn_803A9A80(sp30, spE8);

    if (arg2 & 2) {
        fn_803B847C(sp40, sp10, ctx.mgr, &ctx.f234);
        if (fn_803B3268(sp40, &ctx, 0, sp30, 0x7F, 0) != 0) return 3;
        if ((arg2 & 8) && (ctx.flags & 1)) return 0xA;
        if (ctx.flags & 0x10) return 0x17;
        fn_803B3BA8(&ctx.f222, &sp8);
    } else {
        if ((u32)(n + ctx.f230) > 0x103U) return 1;
        r = fn_803BB3B4(arg0, &ctx, sp30, (u16)n);
        if (r == 8) {
            if (arg2 & 0x10) return 8;
            temp = arg2 & 1;
            if (temp != 0 && has_entry(&ctx, &spC)) return 8;
            if ((ctx.flags & 1) && (temp != 0 || (arg2 & 4) || (arg2 & 8))) return 0xA;
            if (ctx.flags & 0x10) return 0x17;
            if (temp != 0) {
                if (ctx.f234 >= 2U && (u32)(ctx.f234 + 0x10000) != 0xFFFFU && ctx.f228 != 0)
                    fn_803B7780(req + 8, ctx.f234, -1, ctx.f228);
                ctx.f234 = 0;
                ctx.f228 = 0;
                fn_803B3BA8(&ctx.f226, &ctx.f224);
                ctx.f222 = ctx.f226;
            } else {
                fn_803B3BA8(&ctx.f222, &sp8);
            }
        } else if (r != 0) return r;
    }

    arg0 = ctx.mgr;
    owner = fn_803BB1E4(arg0, &ctx);
    if (owner == NULL) return 0x15;
    scan = (Ctx *)arg0;
    for (i = 0; i < 5; i++) {
        if (!(*(u32 *)((u8 *)scan + 0xD10) & 1)) {
            slot = (Slot *)((u8 *)arg0 + 0xD10 + i * 0x30);
            goto found;
        }
        scan = (Ctx *)((u8 *)scan + 0x30);
    }
    slot = NULL;

found:
    if (slot == NULL) {
        if (--owner->f28C == 0) {
            owner->flags &= ~1U;
            owner->f20 = 0;
        }
        return 0x16;
    }

    slot->owner = owner;
    slot->inUse = 1;
    slot->arg2 = arg2;
    slot->f18 = 0;
    slot->f2C = 0;
    fn_803B814C(&slot->pad0C);
    slot->f20 = -1;
    seek_zero(slot, 0);
    if (arg2 & 1) slot->owner->flags |= 4;
    if (slot->arg2 & 4) seek_slot(slot, slot->owner->f264);
    *arg3 = slot;
    return 0;
}
