#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern s32 fn_80392B58(void *, void *);
extern s32 fn_80393350(s32, void *, s32, void *, s32);
extern s32 fn_80393454(s32, void *, void *, s32, s32, void *, s32);
extern s32 fn_803936B0(void *, void *, s32);
extern s32 fn_803974FC(void);
extern void *fn_80397564(s32);
extern void **fn_80397570(s32);
extern u8 *fn_80397578(s32, void *);
extern s32 fn_80397580(void);
extern char lbl_8049170C[];
extern int lbl_8059FC6C;

static inline u8 *get_buffer(u8 *p)
{
    return p + 0x360;
}

s32 fn_80393CF4(void *arg0)
{
    u8 spC[4];
    void *sp8;
    s32 r31;
    s32 r29;
    u8 *r28;
    u8 *r30;
    s32 r27;
    u8 *r31p;
    u8 *ctx;
    s32 t;
    s32 v;

    r31 = fn_803974FC();
    r29 = fn_80397580();
    ctx = *fn_80397570(r31);
    r28 = *(u8 **)(ctx + 0xC);
    r30 = fn_80397578(r31, ctx);
    r31p = fn_80397564(r31);
    sp8 = 0;
    r30 = get_buffer(r30);

    if (*(s32 *)(r28 + 0x248) == 0) {
        if (fn_80393350(r29, r28, 0, &sp8, 0) == 0) {
            return 3;
        }
    } else {
        sp8 = *(void **)(r28 + 0x24C);
    }

    r27 = fn_80392B58(spC, sp8);
    t = fn_803936B0(arg0, lbl_8049170C, 0x10);
    if (t != 0) return t;
    t = fn_803936B0(arg0, spC, r27);
    if (t != 0) return t;
    t = fn_803936B0(arg0, &lbl_8059FC6C, 2);
    if (t != 0) return t;
    t = fn_803936B0(arg0, &lbl_8059FC6C, 2);
    if (t != 0) return t;

    v = *(s32 *)(r28 + 0x248);
    if (v == 0) {
        t = fn_80393454(r29, r28, r30, 0,
                        *(s32 *)(r31p + 0x7D0),
                        (u8 *)arg0 + 0x324, 0);
        if (t != 0) return t;
    } else {
        t = fn_803936B0(arg0, (void *)v, *(s32 *)(r28 + 0x24C));
        if (t != 0) return t;
    }

    return 0;
}
