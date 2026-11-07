#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
typedef struct { int v[64]; } Table;
extern const Table lbl_8040DBE0;
extern u8 lbl_8040DD10[];
extern s32 fn_80261004(u16 *, void *);
extern s32 fn_80260FC0(u8 *, void *);
s32 fn_80263794(void *arg) {
    Table t = lbl_8040DBE0;
    u16 len;
    u8 id, value;
    s32 result;
    u8 *base = (u8 *)arg + 0x44;
    const u8 *p;
    int i, index, product;
    result = fn_80261004(&len, arg);
    if (result < 0) return result;
    len -= 2;
    do {
        len -= 0x41;
        result = fn_80260FC0(&id, arg);
        if (result < 0) return result;
        if (id > 4) return -0x41;
        base[0x1790 + id] = 1;
        p = lbl_8040DD10;
        for (i = 0; i < 64; i++, p++) {
            index = *p;
            if (index > 63) return -0x41;
            result = fn_80260FC0(&value, arg);
            if (result < 0) return result;
            product = value * t.v[index];
            ((int (*)[64])base)[id][index] = product;
            if (product == 0) return -0x41;
        }
    } while (len != 0);
    return 0;
}