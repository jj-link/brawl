#include <types.h>
#pragma force_active on

typedef struct Sub {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[8];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    char pad34[0x438 - 0x34];
    s32 unk438;
} Sub;

typedef struct Req {
    char pad0[8];
    s32 unk8;
    s32 unkC;
    char pad10[4];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    void *unk24;
    void *unk28;
    Sub *unk2C;
    char unk30[8];
    char unk38[0x14];
    char pad4C[0xAC - 0x4C];
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    char padD0[4];
    s32 unkD4;
    char padD8[0x244 - 0xD8];
    s32 unk244;
    char pad248[0x254 - 0x248];
} Req;

extern void *fn_80390044(s32 size, s32 type);
extern void fn_803900A0(void *p);
extern void fn_803900E4(void *ctx, s32 code);
extern void fn_80392738(void *dst, s32 n);
extern void fn_8039272C(void *dst, void *src, s32 n);
extern s32 fn_80392730(char *s);
extern s32 fn_80392744(void *a, void *b, s32 n);
extern s32 fn_80392994(char *p, s32 n);
extern s32 fn_80392D88(char *p, s32 n);
extern char lbl_80416800[];
extern char lbl_80491648[];
extern char lbl_8059FC58[8];

void *fn_803911C8(void *ctx, char *url, s32 len, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s8 dec;
    char sp8[0x100];
    char *src;
    s32 i;
    s32 slashes;
    s32 state;
    s32 prefix;
    s32 rest;
    s32 size;
    s32 port;
    s32 oi;
    s32 seenSlash;
    s32 t;
    char *q;
    Req *obj;
    s32 hostLen;

    obj = 0;
    if (len >= 3 || len < 0) {
        fn_803900E4(ctx, 0xB);
        goto fail;
    }
    obj = fn_80390044(0x254, 4);
    if (obj == 0) {
        fn_803900E4(ctx, 1);
        goto fail;
    }
    fn_80392738(obj, 0x254);
    obj->unk2C = fn_80390044(0x43C, 4);
    if (obj->unk2C == 0) {
        fn_803900E4(ctx, 1);
        goto fail;
    }
    fn_80392738(obj->unk2C, 0x43C);
    obj->unk2C->unk28 = a3;
    obj->unk2C->unk1C = a4;
    obj->unk2C->unk2C = a6;
    obj->unk2C->unk30 = a7;
    a7 = fn_80392730(url);
    if (a7 <= 7) {
        fn_803900E4(ctx, 4);
        goto fail;
    }
    fn_80392738(sp8, a7);
    fn_8039272C(sp8, url, a7);
    obj->unk20 = 0x50;
    prefix = 7;
    if (fn_80392744(sp8, lbl_8059FC58, 7) != 0) {
        if (fn_80392744(sp8, lbl_80491648, 8) != 0) {
            fn_803900E4(ctx, 4);
            goto fail;
        }
        obj->unk8 = 1;
        prefix = 8;
        obj->unk20 = 0x1BB;
    }
    rest = a7 - prefix;
    q = sp8 + prefix;
    if (rest <= 0) {
        fn_803900E4(ctx, 4);
        goto fail;
    }

    src = q;
    i = 0;
    slashes = 0;
    state = 0;
    while (i < rest && *src != '/') {
        if (state == 2) {
            state -= 1;
        } else if (state == 1) {
            dec = fn_80392994(&q[i - 1], 2);
            state -= 1;
            if (dec < 0) {
                fn_803900E4(ctx, 4);
                goto fail;
            }
            if (dec == '/') {
                slashes -= 1;
                break;
            }
        } else if ((s8)*src == '%') {
            state = 2;
            slashes += 1;
        }
        i++;
        src++;
    }
    if (state != 0) {
        fn_803900E4(ctx, 4);
        goto fail;
    }

    size = (prefix + rest) - slashes * 2 + 1;
    obj->unk24 = fn_80390044(size, 4);
    if (obj->unk24 == 0) {
        fn_803900E4(ctx, 1);
        goto fail;
    }
    fn_80392738(obj->unk24, size);
    fn_8039272C(obj->unk24, sp8, prefix);

    i = 0;
    oi = 0;
    state = 0;
    seenSlash = 0;
    while (i < rest) {
        if (state == 2) {
            state -= 1;
        } else if (state == 1) {
            dec = fn_80392994(&q[i - 1], 2);
            ((char *)obj->unk24)[prefix + oi - 1] = (char)dec;
            state -= 1;
            if (dec == '/') {
                seenSlash = 1;
            }
        } else {
            char c = q[i];
            if (c == '/') {
                seenSlash = 1;
            }
            if ((seenSlash == 0) & ((s8)c == '%')) {
                state = 2;
            } else {
                ((char *)obj->unk24)[prefix + oi] = c;
            }
            oi += 1;
        }
        i++;
    }
    ((char *)obj->unk24)[oi + prefix] = 0;

    q = (char *)obj->unk24 + prefix;
    for (t = 0; t < oi; t++) {
        char c = q[t];
        if (c == '/' || c == ':') {
            obj->unk14 = t + prefix;
            break;
        }
    }
    if (t == oi) {
        obj->unk14 = t + prefix;
        obj->unk18 = t + prefix;
    } else if (q[t] == '/') {
        obj->unk18 = obj->unk14;
    } else if (q[t] == ':') {
        for (; t < oi; t++) {
            if (q[t] == '/') {
                obj->unk18 = t + prefix;
                break;
            }
        }
        if (t == oi) {
            obj->unk18 = t + prefix;
        } else {
            s32 portStart = obj->unk14 + 1;
            port = fn_80392D88((char *)obj->unk24 + portStart, obj->unk18 - portStart);
            if (port < 0) {
                port = obj->unk20;
            } else if (port > 0xFFFF) {
                fn_803900E4(ctx, 4);
                goto fail;
            }
            obj->unk20 = (s32)(u16)port;
        }
    }

    hostLen = obj->unk14 - ((obj->unk8 != 0) + 7);
    obj->unk28 = fn_80390044(hostLen + 1, 4);
    if (obj->unk28 == 0) {
        fn_803900E4(ctx, 1);
        goto fail;
    }
    fn_80392738(obj->unk28, hostLen + 1);
    fn_8039272C(obj->unk28, (char *)obj->unk24 + (obj->unk8 ? 8 : 7), hostLen);
    fn_8039272C(obj->unk38, lbl_80416800, 0x14);
    obj->unk1C = len;
    obj->unkAC = 0;
    obj->unkB0 = 0;
    obj->unkB4 = 0;
    obj->unkB8 = 0;
    obj->unkBC = 0;
    obj->unkC0 = 0;
    obj->unkC4 = 0;
    obj->unkC8 = 0;
    obj->unkCC = 0;
    obj->unkD4 = 0;
    obj->unk2C->unk438 = a5;
    obj->unkC = 0;
    obj->unk244 = 0;
    return obj;

fail:
    if (obj != 0) {
        if (obj->unk24 != 0) {
            fn_803900A0(obj->unk24);
        }
        if (obj->unk28 != 0) {
            fn_803900A0(obj->unk28);
        }
        if (obj->unk2C != 0) {
            fn_803900A0(obj->unk2C);
        }
        fn_803900A0(obj);
    }
    return 0;
}
