#pragma force_active on
typedef unsigned char u8;
typedef signed int s32;

extern s32 fn_803974FC(void);
extern s32 **fn_80397570(void);
extern s32 fn_80397578(s32);
extern void *fn_80397564(s32);
extern s32 fn_80397580(s32);
extern s32 fn_80392344(s32, void *, void *, void *, s32, s32);
extern s32 fn_80392744(void *, void *, s32);
extern s32 fn_80392AB8(void *, s32);
extern u8 lbl_8059FC70;

s32 fn_80393A04(void) {
    u8 buf[0x200];
    s32 root;
    s32 **pp;
    s32 base;
    void *cfg;
    s32 h;
    void *off;
    void *obj;
    s32 *sub;
    s32 flag;
    s32 total;
    s32 r;
    u8 *p;
    s32 i;
    s32 hit;

    root = fn_803974FC();
    pp = fn_80397570();
    base = fn_80397578(root);
    cfg = fn_80397564(root);
    h = fn_80397580(root);
    off = (void *)(base + 0x360);
    flag = 0;
    obj = (void *)(*pp)[3];
    total = 0;
    sub = (s32 *)((s32 *)obj)[11];

    for (;;) {
        r = fn_80392344(h, obj, *(void **)((u8 *)cfg + 0x7D0), buf + total, 0x200 - total, 0);
        total += r;
        sub[6] = fn_80392AB8(buf + 9, 3);
        if (fn_80392744(buf, &lbl_8059FC70, 5) == 0 && (s32)buf[8] == 0x20 && sub[6] == 0xC8) {
            flag = 1;
        }
        p = buf;
        i = 0;
        hit = 0;
        for (; i < total; i++) {
            if (i > 1 && (s32)p[-1] == 0x0D && (s32)p[0] == 0x0D) {
                hit = 1;
            } else if (i > 1 && (s32)p[-1] == 0x0A && (s32)p[0] == 0x0A) {
                hit = 1;
            } else if (i > 3 && (s32)p[-3] == 0x0D && (s32)p[-2] == 0x0A && (s32)p[-1] == 0x0D && (s32)p[0] == 0x0A) {
                hit = 1;
            }
            p++;
        }
        if (hit) {
            return flag != 0;
        }
        if (r < 0) {
            return 0;
        }
        if (total >= 0x200) {
            r = fn_80392344(h, obj, *(void **)((u8 *)cfg + 0x7D0), off, 1, 0);
            if (r < 0) {
                return 0;
            }
            if (r != 0) {
                return 0;
            }
        }
    }
}
