#include <types.h>
#pragma force_active on
extern s32 fn_8039832C(void *, s32, u32);
extern s32 fn_80398680(void *);
extern s32 fn_80398818(void *, u32, u32);
extern s32 fn_80398A08(s32, s32, void *);
extern u32 fn_80399AC8(void);
extern s32 fn_803A3540(u16 *, s32);
extern s32 lbl_8059FDE8;
extern s32 lbl_805A1170;
s32 fn_803A3324(s32 arg0) {
    unsigned char ctx[0x9C];
    unsigned char *tbl;
    unsigned char *b0;
    unsigned char *b1;
    unsigned char *b2;
    u16 idx;
    u16 index;
    u32 cur;
    s32 result;
    s32 ret;
    s32 close_result;
    cur = fn_80399AC8();
    tbl = (unsigned char *)lbl_805A1170;
    b0 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *)0);
    if (b0 == 0) result = -9;
    else if (cur == 0) result = -3;
    else {
        result = fn_803A3540(&idx, 1);
        goto loop_check;
loop_body:
        index = idx;
        tbl = (unsigned char *)lbl_805A1170;
        b1 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *)0);
        if (cur == *(u32 *)(b1 + (((u32)index * 0x10) & 0xFFFF0) + 0x80)) {
            result = 0;
            goto done_loop;
        }
        result = fn_803A3540(&idx, 0);
loop_check:
        if (result >= 0) goto loop_body;
        result = -0xD;
done_loop:
        ;
    }
    if (result < 0) return result;
    index = idx;
    tbl = (unsigned char *)lbl_805A1170;
    b0 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *)0);
    if (b0 == 0) return -9;
    b1 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *)0);
    if (index >= *(u16 *)(b1 + 0x14) || index == 0xFFFF) result = -3;
    else {
        b2 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *)0);
        result = 0;
        if (*(u32 *)(b2 + (((u32)index * 0x10) & 0xFFFF0) + 0x80) == 0) result = -0xD;
    }
    if (result < 0) return result;
    result = fn_8039832C(ctx, lbl_8059FDE8, 0xA);
    if (result < 0) return result;
    tbl = (unsigned char *)lbl_805A1170;
    b1 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *)0);
    if (*(u16 *)(b1 + 0x14) > 0x78 || index >= *(u16 *)(b1 + 0x14)) result = -3;
    else result = fn_80398818(ctx, (((u32)index << 9) & 0x1FFFE00) + 0x800, 0);
    if (result < 0) ret = result;
    else {
        result = fn_80398A08(arg0, 0x200, ctx);
        ret = 0;
        if (result < 0) ret = result;
    }
    close_result = fn_80398680(ctx);
    if (ret != 0) close_result = ret;
    return close_result;
}
