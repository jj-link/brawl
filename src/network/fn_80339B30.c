#include <types.h>
#pragma force_active on

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    s32 unk28;
    u8 pad2C[0x68 - 0x2C];
    void *unk68;
    void *unk6C;
    void *unk70;
    void *unk74;
    u8 pad78[0x818 - 0x78];
    u64 unk818;
} Obj;

extern void fn_80335638(int, const char *, ...);
extern s32 fn_80335238(void);
extern u32 fn_80336674(u16 *);
extern void fn_8034F028(void *, const void *, u32);
extern s32 fn_8035C788(const char *);
extern void fn_8035E02C(void *, u32);
extern void *memset(void *, int, u32);
extern s32 sprintf(char *, const char *, ...);
extern u64 OSGetTime(void);
extern char lbl_80489E48[];
extern char lbl_80535BE0[];
extern char lbl_804942B8[];
extern Obj *lbl_805A0F88;

s32 DWC_LoginAsync(u16 *arg0, s32 p2, void *p3, void *p4) {
    const char *base = lbl_80489E48;
    char buf[0x100];
    u32 len;
    u8 *tbl;
    const char *s;
    u32 hash;
    u64 t;

    fn_80335638(4, base + 0x90);
    if (arg0 == 0) {
        fn_80335638(8, base + 0xB4);
        return 0;
    }
    if (fn_80335238() != 0 || lbl_805A0F88->unk24 != 0) {
        fn_80335638(4, base + 0xC8);
        return 0;
    }

    lbl_805A0F88->unk70 = p3;
    lbl_805A0F88->unk74 = p4;

    if (arg0 == 0 || *arg0 == 0) {
        len = 0;
    } else {
        memset((u8 *)lbl_805A0F88 + 0x2E, 0, 0x34);
        if (fn_80336674(arg0) <= 0x19) {
            len = fn_80336674(arg0);
        } else {
            len = 0x19;
        }
        fn_8034F028((u8 *)lbl_805A0F88 + 0x2E, (const char *)arg0, len * 2);
    }

    *(u16 *)((u8 *)lbl_805A0F88 + 0x2E + len * 2) = 0;

    if (fn_8035C788(base + 0xD8) == 0)
        goto fail;
    if (fn_8035C788(base + 0xF4) == 0)
        goto fail;
    if (fn_8035C788(base + 0x110) == 0)
        goto fail;
    if (fn_8035C788(base + 0x130) == 0)
        goto fail;

    s = lbl_80535BE0;
    if (s == 0)
        goto ok;

    sprintf(buf, base + 0x150, s);
    if (fn_8035C788(buf) == 0)
        goto fail;
    sprintf(buf, base + 0x174, s);
    if (fn_8035C788(buf) == 0)
        goto fail;
    sprintf(buf, base + 0x194, s);
    if (fn_8035C788(buf) == 0)
        goto fail;
    sprintf(buf, base + 0x1B4, s);
    if (fn_8035C788(buf) == 0)
        goto fail;
    sprintf(buf, base + 0x1D4, s);
    if (fn_8035C788(buf) == 0)
        goto fail;
    sprintf(buf, base + 0x1F4, s);
    if (fn_8035C788(buf) == 0)
        goto fail;
    sprintf(buf, base + 0x218, s);
    if (fn_8035C788(buf) == 0)
        goto fail;

    tbl = *(u8 **)(lbl_804942B8 + 0x38);
    hash = 0;
    while (*s != 0) {
        s32 c = *s;
        hash = hash * 0x9CCF9319 + ((c < 0 || c >= 0x100) ? c : *(u8 *)(*(u8 **)(tbl + 0x10) + c));
        s++;
    }

    sprintf(buf, base + 0x23C, lbl_80535BE0, hash % 20);
    if (fn_8035C788(buf) != 0)
        goto ok;

fail:
    fn_80335638(8, base + 0x258);

ok:
    t = OSGetTime();
    lbl_805A0F88->unk818 = t;
    lbl_805A0F88->unk28 = lbl_805A0F88->unk24;
    lbl_805A0F88->unk24 = 1;
    fn_8035E02C(lbl_805A0F88->unk68, (u32)t);
    return 1;
}