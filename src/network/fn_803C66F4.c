#include <types.h>
#pragma force_active on
extern u32 lbl_805A1210;
extern u32 lbl_805A1220;
extern int lbl_805A1214;
extern void fn_803C7D64(int, int);
extern int fn_803C2D4C(s8, void *);
extern int fn_803C2AB0(void);
typedef struct { int a0, a4, a8, ac, a10; s8 a14; } Entry;
typedef struct { int a, b, c, d; } Info;
int fn_803C66F4(u32 arg0) {
    Entry *e;
    Info info;
    int r;
    if (arg0 < lbl_805A1210 && lbl_805A1220 != 0)
        e = (Entry *)(lbl_805A1220 + arg0 * 0x140);
    else
        e = 0;
    if (e == 0 || e->a0 == 0) {
        lbl_805A1214 = 0xB003;
        return -1;
    }
    if (e->a8 == 0) {
        lbl_805A1214 = 0xB003;
        return -1;
    }
    if (e != 0 && e->a8 != 0)
        fn_803C7D64(e->a8, 0);
    if (fn_803C2D4C(e->a14, &info) != 0) {
        r = fn_803C2AB0();
        if (r != 0)
            lbl_805A1214 = r;
        return -1;
    }
    return info.d * (info.b * info.c);
}