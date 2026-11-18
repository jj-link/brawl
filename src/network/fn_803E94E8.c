#include <types.h>
#pragma force_active on

extern int fn_803D6E5C(void);
extern int fn_803D7168(char *, s32);
extern int fn_803DA314(char *);
extern int fn_803DD968(char *, char *);
extern int fn_803DD9DC(char *);
extern int fn_803E1E24(char *);
extern void fn_803EBBDC(s32 *);
extern char lbl_805644C0[];

static inline int find_id(int id)
{
    unsigned int i;
    char *entry = lbl_805644C0 + 8;
    for (i = 1; i < 4; i++) {
        if ((*(unsigned int *)(entry + 0x80) &= 1) &&
            id == *(int *)(entry + 0x84)) return 1;
        entry += 8;
    }
    return 0;
}

int fn_803E94E8(char *arg0)
{
    s32 sp8;
    u32 cnt;
    char *q;
    s32 r, v;
    u16 h;
    s32 var_r3;

    *(s32 *)(arg0 + 0x1F80) = 0;
    *(s32 *)(arg0 + 0x1F84) = 0;
    r = fn_803D6E5C();
    if (r != 0)
        return r;

    h = *(u16 *)arg0;
    if (((s32)h == 0) || (h & 0x1FF))
        return 0xF;

    v = (h >> 9) & 0x7F;
    if (v > (s32)*(u16 *)(arg0 + 0x1628) ||
        (v * 2) > (s32)*(u16 *)(arg0 + 0x162A))
        return 0x1E;

    r = fn_803DA314(arg0);
    if (r != 0)
        return r;

    h = *(u16 *)(arg0 + 0x1F8C) | 8;
    *(u16 *)(arg0 + 0x1F8C) = h;
    if (!(h & 8)) {
        var_r3 = 9;
    } else {
        fn_803EBBDC(&sp8);
        *(s32 *)(arg0 + 0x1654) |= 1;
        if (find_id(sp8)) {
            *(s32 *)(arg0 + 0x189C) |= 1;
            *(s32 *)(arg0 + 0x18A0) = sp8;
        }

        q = arg0 + 0x165C;
        cnt = 0;
        do {
            r = fn_803DD968(arg0, q);
            if (r != 0) {
                var_r3 = r;
                goto done;
            }
            cnt++;
            q += 0x248;
        } while (cnt < 4);
        var_r3 = 0;
    }

done:
    if (var_r3 == 0 && (*(u16 *)(arg0 + 0x1F8C) & 0x40)) {
        var_r3 = fn_803D7168(arg0, *(s32 *)(arg0 + 0x1FC4));
        if (var_r3 == 0 && !(*(u16 *)(arg0 + 0x1F8C) & 0x80)) {
            var_r3 = fn_803E1E24(arg0);
            if (var_r3 == 0)
                var_r3 = fn_803DD9DC(arg0);
        }
    }

    if (var_r3 != 0)
        *(u16 *)(arg0 + 0x1F8C) &= ~8;
    return var_r3;
}
