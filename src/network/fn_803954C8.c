#pragma force_active on
#include <types.h>

extern void *fn_803974FC(void);
extern void *fn_80397564(void *);
extern void **fn_80397570(void *);
extern s32 fn_80397578(void *);
extern s32 fn_80397580(void *);
extern void fn_80397588(s32 *, s32);
extern s32 *fn_803970CC(s32, void *);
extern s32 fn_803935E4(s32, void *);
extern s32 fn_80391180(s32, void *, void *, s32, s32, s32);
extern s32 fn_80391160(s32, void *, void *, s32, s32);
extern s32 fn_80391144(void *, s32);
extern s32 fn_80392344(s32, void *, void *, void *, s32, s32);
extern s32 fn_80392994(void *, s32);
extern s32 fn_803970D4(s32, void *);
extern void fn_8039738C(s32, s32);

static inline s32 skipCRLF(s32 ctx, void *obj, void *stream)
{
    u8 buf[2];
    s32 j;
    s32 n;
    s32 r;

    n = 0;
    buf[0] = 0;
    buf[1] = 0;
    j = 0;
    while ((s32)buf[j & 1] != 0xd || (s8)buf[(j - 1) & 1] != 0xa) {
        r = fn_80392344(ctx, obj, stream, &buf[j & 1], 1, 0);
        if (r <= 0)
            return r;
        n += r;
        j++;
    }
    return n;
}

s32 fn_803954C8(u8 *arg0)
{
    u8 c;
    u8 *cfg;
    s32 m;
    s8 *p10;
    u8 *obj;
    u8 *sub;
    s32 ctx;
    s32 *entry;
    u8 *base;
    s32 i;
    s32 r;
    void *root;
    u8 sp10[2];

    root = fn_803974FC();
    obj = *(u8 **)((u8 *)*fn_80397570(root) + 0xc);
    sub = *(u8 **)(obj + 0x2c);
    cfg = fn_80397564(root);
    ctx = fn_80397580(root);
    entry = fn_803970CC(ctx, obj);
    base = (u8 *)(fn_80397578(root) + 0x360);

    if (*(s32 *)(obj + 0x1c) == 2 ||
        *(s32 *)(sub + 0x18) == 0xcc ||
        *(s32 *)(sub + 0x18) == 0x130 ||
        (*(s32 *)(sub + 0x18) >= 0x64 && *(s32 *)(sub + 0x18) < 0xc8))
        return 1;

    fn_80397588(entry, 0);
    if (entry != 0)
        *entry = 4;

    if (*(s32 *)(arg0 + 0x32c) >= 0) {
        fn_80397588(entry, *(s32 *)(arg0 + 0x32c));
        while (*(s32 *)(arg0 + 0x32c) > 0) {
            if (*(s32 *)(arg0 + 0x330) != 6 && fn_803935E4(ctx, sub) == 0) {
                *(s32 *)(arg0 + 0x330) = 6;
                *(void **)(sub + 0x28) = (void *)(arg0 + 0x104);
                *(s32 *)(sub + 0x1c) = 0x200;
            }
            if (*(s32 *)(arg0 + 0x330) == 6)
                r = fn_80391180(ctx, obj, *(void **)(cfg + 0x7d0), 0,
                               *(s32 *)(arg0 + 0x32c), 0);
            else
                r = fn_80391180(ctx, obj, *(void **)(cfg + 0x7d0),
                               *(s32 *)(sub + 4), *(s32 *)(arg0 + 0x32c), 0);
            if (r < 0)
                return 0;
            if (r == 0)
                break;
            if (*(s32 *)(arg0 + 0x330) != 6) {
                *(s32 *)(sub + 4) += r;
                *(s32 *)(sub + 8) += r;
            }
            *(s32 *)(arg0 + 0x32c) -= r;
        }
        if (*(s32 *)(arg0 + 0x330) != 6) {
            if (*(s32 *)(arg0 + 0x32c) != 0) {
                *(s32 *)(arg0 + 0x330) =
                    fn_80391144(sub, *(s32 *)(sub + 4)) != 0 ? 6 : 0xa;
            } else {
                *(s32 *)(arg0 + 0x330) = 0;
            }
        }
        goto final;
    }

    *(s32 *)(arg0 + 0x330) = 0xa;
    if (*(s32 *)(arg0 + 0x33c) != 0) {
        m = -1;
        for (;;) {
            p10 = (s8 *)sp10;
            sp10[0] = 0;
            sp10[1] = 0;
            *(s32 *)(arg0 + 0x328) = 0;
            while (*(s32 *)(arg0 + 0x328) < 0x100) {
                if (fn_80392344(ctx, obj, *(void **)(cfg + 0x7d0),
                                base + *(s32 *)(arg0 + 0x328), 1, 0) < 0)
                    return 0;
                i = *(s32 *)(arg0 + 0x328);
                p10[i & 1] = base[i];
                c = p10[i & 1];
                if ((s8)c == 0x3b ||
                    ((s8)c == 0xa && p10[(i - 1) & 1] == 0xd)) {
                    if ((s8)c == 0xa) {
                        i--;
                    } else {
                        r = skipCRLF(ctx, obj, *(void **)(cfg + 0x7d0));
                        if (r <= 0)
                            return 0;
                    }
                    if (i == 0)
                        return 0;
                    m = fn_80392994(base, i);
                    if (m < 0)
                        return 0;
                    break;
                }
                *(s32 *)(arg0 + 0x328) += 1;
            }
            if (*(s32 *)(arg0 + 0x328) == 0x100) {
                *(s32 *)(arg0 + 0x330) = 7;
                return 0;
            }
            if (m > 0) {
                fn_80397588(entry, m);
                while (m > 0) {
                    if (*(s32 *)(arg0 + 0x330) != 6 &&
                        fn_803935E4(ctx, sub) == 0) {
                        *(s32 *)(arg0 + 0x330) = 6;
                        *(void **)(sub + 0x28) = (void *)(arg0 + 0x104);
                        *(s32 *)(sub + 0x1c) = 0x200;
                    }
                    if (*(s32 *)(arg0 + 0x330) == 6)
                        r = fn_80391180(ctx, obj, *(void **)(cfg + 0x7d0),
                                       0, m, 0);
                    else
                        r = fn_80391180(ctx, obj, *(void **)(cfg + 0x7d0),
                                       *(s32 *)(sub + 4), m, 0);
                    if (r <= 0)
                        return 0;
                    m -= r;
                    *(s32 *)(sub + 4) += r;
                    *(s32 *)(sub + 8) += r;
                    if (m == 0 &&
                        fn_80392344(ctx, obj, *(void **)(cfg + 0x7d0),
                                    base, 2, 0) <= 0)
                        return 0;
                }
            } else {
                skipCRLF(ctx, obj, *(void **)(cfg + 0x7d0));
                *(s32 *)(arg0 + 0x330) = 0;
                goto final;
            }
        }
    }

    for (;;) {
        if (fn_803935E4(ctx, sub) == 0) {
            *(s32 *)(arg0 + 0x330) = 6;
            *(void **)(sub + 0x28) = (void *)(arg0 + 0x104);
            *(s32 *)(sub + 0x1c) = 0x200;
        }
        if (*(s32 *)(arg0 + 0x330) == 6)
            r = fn_80391160(ctx, obj, *(void **)(cfg + 0x7d0), 0, 0);
        else
            r = fn_80391160(ctx, obj, *(void **)(cfg + 0x7d0),
                            *(s32 *)(sub + 4), 0);
        if (r < 0)
            return 0;
        if (r == 0) {
            if (*(s32 *)(arg0 + 0x330) != 6)
                *(s32 *)(arg0 + 0x330) = 0;
            goto final;
        }
        *(s32 *)(sub + 4) += r;
        *(s32 *)(sub + 8) += r;
    }

final:
    r = fn_803970D4(ctx, sub);
    if (*(s32 *)(arg0 + 0x330) == 0 && r != 0)
        fn_8039738C(ctx, r);
    return 1;
}
