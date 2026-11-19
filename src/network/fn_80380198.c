#include <string.h>
#include <stdio.h>
#include <types.h>
#include <revolution/SO/SOBasic.h>

#pragma force_active on

typedef struct Hdr {
    u8 flags;
    u8 type;
    s16 len1;
    s16 len2;
    s16 len3;
    s32 val;
} Hdr;

extern s32 fn_80362F5C(s32);
extern s32 fn_8037B7B4(u8 *, char *, s32);
extern void fn_8037BBB8(u8 *);
extern s32 fn_8037BBDC(u8 *);
extern s32 fn_8037C1C0(u8 *, char *, s32);
extern s32 fn_8037FB20(u8 *, u8 *);
extern s32 fn_8037FCCC(u8 *, u8 *);
extern s32 fn_8037FE60(u8 *, u8 *);
extern s32 fn_8037FFA0(u8 *, u8 *);

extern char lbl_80490690[];
extern char lbl_8059FA80;
extern char lbl_8059FA88;
extern char lbl_8059FA8C;

s32 fn_80380198(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    Hdr hdr14;
    Hdr hdr8;
    char buf[0x800];
    char *base;
    char *dst;
    char *format;
    char *bufBase;
    char *p;
    u8 *cfg;
    u8 *ent;
    s32 type;
    char *name;
    char *r30;
    s32 r26;
    s32 v7;
    s32 len;
    s32 n;
    s32 n2;
    s32 ctr;
    s32 ret;

    base = lbl_80490690;
    len = 0;

    if (*(s32 *)(arg0 + 4) == -1) {
        *(s32 *)(arg0 + 4) = 0;
        cfg = *(u8 **)(arg1 + 0x160);

        if (*(s32 *)(cfg + 0xC) == 0 && *(s32 *)(cfg + 0x10) == 0) {
            if (arg2 != 0) {
                sprintf(buf, &lbl_8059FA88,
                        *(char **)(*(u8 **)arg0 + 4));
            } else {
                sprintf(buf, &lbl_8059FA8C,
                        *(char **)(*(u8 **)arg0 + 4));
            }
        } else {
            ent = *(u8 **)arg0;
            type = *(s32 *)ent;

            if (type == 0) {
                dst = buf;
                format = base + 0x138;
                p = base + 0x190;
                sprintf(dst, format,
                        arg2 != 0 ? (p = base + 0x168) : p,
                        *(char **)(ent + 4));
            } else if (type == 3) {
                if (*(s32 *)(cfg + 0x14) != 0) {
                    hdr14.flags = 8;
                    if (arg2 != 0) {
                        hdr14.flags |= 4;
                    }
                    if (arg3 != 0) {
                        hdr14.flags |= 2;
                    }
                    hdr14.type = 0x20;
                    hdr14.len1 = 0;
                    hdr14.len2 = SOHtoNs((u16)strlen(&lbl_8059FA80));
                    hdr14.len3 = SOHtoNs((u16)strlen(base + 0xF4));
                    hdr14.val = SOHtoNl(
                        fn_80362F5C(*(s32 *)(*(u8 **)arg0 + 8)));

                    memcpy(buf, &hdr14, 0xC);
                    strcpy(buf + 0xC, &lbl_8059FA80);

                    len = strlen(&lbl_8059FA80) + 0xC;
                    n = 4 - (strlen(&lbl_8059FA80) & 3);
                    if (n != 4) {
                        for (; n > 0; n--) {
                            buf[len++] = 0;
                        }
                    }

                    strcpy(buf + len, base + 0xF4);
                    len += strlen(base + 0xF4);
                    n = 4 - (strlen(base + 0xF4) & 3);
                    if (n != 4) {
                        for (; n > 0; n--) {
                            buf[len++] = 0;
                        }
                    }
                } else {
                    buf[0] = 0;
                }
            } else if ((u32)(type - 1) <= 1) {
                if (type == 1) {
                    r26 = *(s32 *)(arg0 + 0xC);
                    v7 = *(s32 *)(ent + 0xC);
                    r30 = *(char **)(ent + 0x10);
                } else {
                    r26 = *(s32 *)(ent + 0xC);
                    v7 = *(s32 *)(ent + 0x10);
                    r30 = *(char **)(ent + 0x14);
                }

                if (*(s32 *)(cfg + 0x14) != 0) {
                    hdr8.flags = 8;
                    if (arg2 != 0) {
                        hdr8.flags |= 4;
                    }
                    if (arg3 != 0) {
                        hdr8.flags |= 2;
                    }
                    hdr8.type = 0x10;
                    hdr8.len1 = 0;
                    hdr8.len2 = SOHtoNs(
                        (u16)strlen(*(char **)(*(u8 **)arg0 + 4)));
                    hdr8.len3 = SOHtoNs((u16)strlen(r30));
                    hdr8.val = SOHtoNl(r26);

                    memcpy(buf, &hdr8, 0xC);
                    strcpy(buf + 0xC, *(char **)(*(u8 **)arg0 + 4));

                    name = *(char **)(*(u8 **)arg0 + 4);
                    len = strlen(name) + 0xC;
                    n = 4 - (strlen(name) & 3);
                    if (n != 4) {
                        for (; n > 0; n--) {
                            buf[len++] = 0;
                        }
                    }

                    strcpy(buf + len, r30);
                    len += strlen(r30);
                    n = 4 - (strlen(r30) & 3);
                    if (n != 4) {
                        for (; n > 0; n--) {
                            buf[len++] = 0;
                        }
                    }
                } else {
                    dst = buf;
                    format = base + 0x1BC;
                    p = base + 0x190;
                    sprintf(dst, format,
                            arg2 != 0 ? (p = base + 0x168) : p,
                            *(char **)(ent + 4), v7, r30);
                }
            }
        }

        if (*(s32 *)(arg1 + 0x194) == 0) {
            if (len == 0) {
                len = strlen(buf);
            }

            ret = fn_8037C1C0(arg1, buf, len);
            if (ret == 0) {
                return 0;
            }
            if (ret == 2) {
                return 2;
            }
            fn_8037BBB8(arg1 + 0x54);
        } else {
            if (len == 0) {
                len = strlen(buf);
            }

            ret = fn_8037B7B4(arg1 + 0x54, buf, len);
            if (ret == 0) {
                return 0;
            }

            ret = fn_8037BBDC(arg1);
            if (ret == 0) {
                return 0;
            }

            if (*(s32 *)(arg1 + 0x64) < *(s32 *)(arg1 + 0x60)) {
                return 2;
            }
            fn_8037BBB8(arg1 + 0x54);
        }
    }

    ret = *(s32 *)(*(u8 **)arg0);
    if (ret == 0) {
        return fn_8037FB20(arg0, arg1);
    }
    if (ret == 3) {
        return fn_8037FCCC(arg0, arg1);
    }
    if (ret == 1) {
        return fn_8037FE60(arg0, arg1);
    }
    return fn_8037FFA0(arg0, arg1);
}
