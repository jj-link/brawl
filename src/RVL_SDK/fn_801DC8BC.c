#pragma force_active on
#include <types.h>

extern int lbl_805A06B4;
extern int lbl_805A06B8;
extern int lbl_805A06BC;

extern u8 *fn_801E21E8(u8 *, u32 *);
extern u8 *fn_801E22F8(u8 *, u32 *);
extern u8 fn_801E2368(u32);
extern u16 fn_801E23E0(u32);
extern s32 fn_801DBFEC(s32, u16);

static inline int is_lead(u32 c)
{
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc);
}

static inline int is_trail(u32 c)
{
    return c >= 0x40 && c <= 0xfc && c != 0x7f;
}

u8 *fn_801DC8BC(int mode, u8 *str, int *table, int *result, int unused)
{
    u32 sp8;
    unsigned int t;
    u16 c;
    u32 c2;

    c = 0;
    sp8 = c;

    switch (mode) {
    case 0:
        c = *str;
        t = (u32)lbl_805A06BC;
        if (c != 0)
            str++;
        break;
    case 1:
        c = *str;
        t = (u32)lbl_805A06B8;
        if (c != 0) {
            str++;
            if (is_lead(c)) {
                c2 = *str;
                if (is_trail(c2))
                    c = (c << 8) | *str++;
            }
        }
        break;
    case 3:
        str = fn_801E21E8(str, &sp8);
        break;
    case 4:
        str = fn_801E22F8(str, &sp8);
        break;
    case 5:
        c2 = *(u32 *)str;
        sp8 = c2;
        if (sp8 != 0)
            str += 4;
        break;
    }

    if (sp8 != 0) {
        t = (u32)lbl_805A06BC;
        mode = 0;
        c = fn_801E2368(sp8);
        if (c == 0 || (lbl_805A06B4 != 0 && sp8 <= 0x7f)) {
            c = fn_801E23E0(sp8);
            if (c != 0) {
                mode = 1;
                t = (u32)lbl_805A06B8;
            }
        }
    }

    *table = t;
    *result = fn_801DBFEC(mode, c);
    return str;
}