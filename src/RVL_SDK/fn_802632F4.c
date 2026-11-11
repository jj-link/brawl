#include <types.h>
#pragma force_active on
#pragma optimization_level 3
#pragma use_lmw_stmw on

extern s32 fn_80261004(u16 *, void *);
extern s32 fn_80260FC0(u8 *, void *);
extern s32 fn_80261108(s32, void *);
extern s32 fn_802635B4(u16, void *);
extern s32 fn_80263794(void *);

static inline s32 parse_app(u16 *size, void *arg) {
    s32 r = fn_80261004(size, arg);
    if (r < 0) return r;
    if (*size < 2) return -0x45;
    *size -= 2;
    r = fn_80261108(*size, arg);
    r = r & (r >> 31);
    return r & (r >> 31);
}

static inline s32 parse_dri(u16 *size, void *arg) {
    s32 r = fn_80261004(size, arg);
    if (r < 0) return r;
    if (*size != 4) return -0x42;
    r = fn_80261004(size, arg);
    if (r < 0) return r;
    *(u16 *)((u8 *)arg + 0x1806) = *size;
    return 0;
}

static inline s32 parse_dnl(u16 *size, void *arg) {
    s32 r = fn_80261004(size, arg);
    if (r < 0) return r;
    if (*size != 4) return -0x43;
    r = fn_80261004(size, arg);
    if (r < 0) return r;
    *(u16 *)((u8 *)arg + 0x17DE) = *size;
    return 0;
}

static inline s32 parse_comment(u16 *size, void *arg) {
    s32 r = fn_80261004(size, arg);
    if (r < 0) return r;
    if (*size < 2) return -0x44;
    *size -= 2;
    r = fn_80261108(*size, arg);
    r = r & (r >> 31);
    return r & (r >> 31);
}

s32 fn_802632F4(u16 *arg0, void *arg1) {
    u16 sp12, sp10, spE, spC, spA;
    u8 sp8;
    s32 r;
    s32 stop = 0;
    u16 saved;
    u8 *p = (u8 *)arg1;
    saved = *arg0;
    do {
        r = fn_80261004(&sp12, arg1);
        if (r < 0) return r;
        while (sp12 == 0xFFFF) {
            r = fn_80260FC0(&sp8, arg1);
            if (r < 0) return r;
            sp12 = sp8 | 0xFF00;
        }
        if (sp12 >= 0xFFE0 && sp12 <= 0xFFEF) {
            r = parse_app(&sp10, arg1);
        } else {
            switch ((s32)sp12) {
            case 0xFFC4: r = fn_802635B4(saved, arg1); break;
            case 0xFFDB: r = fn_80263794(arg1); break;
            case 0xFFDD:
                r = parse_dri(&spE, arg1);
                break;
            case 0xFFDC:
                r = parse_dnl(&spC, arg1);
                break;
            case 0xFFFE:
                r = parse_comment(&spA, arg1);
                break;
            case 0xFFC0: stop = 1; break;
            case 0xFFC2: stop = 1; break;
            case 0xFFDA: stop = 1; break;
            case 0xFFD9: p[0x1808] = 1; stop = 1; break;
            default: r = -0x2F; break;
            }
        }
        if (r < 0) stop = 1;
    } while (!stop);
    *arg0 = sp12;
    return r;
}
