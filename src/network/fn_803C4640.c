#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
extern int fn_80204738(void *);
extern int fn_80204818(int, int);
extern s32 lbl_80563218[];
extern u32 lbl_805A1210;
extern u32 lbl_805A1218;
extern u32 lbl_805A121C;
extern u32 lbl_805A1220;
void fn_803C4640(void) {
    u32 end;
    s32 i;
    int *f;
    u32 n;
    u32 r28;
    s32 *q;
    u32 p;
    if (lbl_805A1220 != 0) {
        if (lbl_805A1210 != 0 && lbl_805A1220 != 0) {
            p = lbl_805A1220;
        } else {
            p = 0;
        }
        if (p != 0) {
            end = p + lbl_805A1210 * 0x140;
            for (; p != end; p += 0x140) {
                if (p != 0) {
                    f = (int *)(p + 0x1C);
                    r28 = f[0];
                    if (f != 0) {
                        if (f[2] != 0 && r28 != 0) {
                            fn_80204818(r28, f[2]);
                        }
                        if (f[3] != 0 && f[0] != 0) {
                            fn_80204818(f[0], f[3]);
                        }
                        if (f != 0) {
                            f[0] = 0;
                            f[1] = 0;
                            f[2] = 0;
                            f[3] = 0;
                        }
                    }
                    if (r28 != lbl_805A1218 && r28 != 0) {
                        fn_80204738((void *)r28);
                    }
                }
            }
        }
        {
            int a = lbl_805A1218;
            int b = lbl_805A1220;
            if (a != 0) {
                fn_80204818(a, b);
            }
        }
        lbl_805A1220 = 0;
    }
    n = lbl_805A1210;
    if (lbl_805A121C != 0) {
        for (i = 0, q = lbl_80563218; (u32)i < n; q++, i++) {
            if (*q != 0) {
                if (lbl_805A1218 != 0) {
                    fn_80204818(lbl_805A1218, *q);
                }
                *q = 0;
            }
        }
        lbl_805A121C = 0;
    }
    if (lbl_805A1218 != 0) {
        fn_80204738((void *)lbl_805A1218);
        lbl_805A1218 = 0;
    }
    lbl_805A1210 = 0;
}