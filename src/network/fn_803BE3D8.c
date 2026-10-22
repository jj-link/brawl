#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern u16 fn_803A9C60(void);
extern u16 fn_803A9C74(int, int);
extern int fn_803A9DF8(int, void *, int, int, int);
extern void fn_803A9F10(int, int, u8 *);
extern void *fn_803C1668(s8);
extern void *fn_803C1514(void);
extern char lbl_8059FE60[2];

void *fn_803BE3D8(int arg0)
{
    u8 sp8;

    if (fn_803A9C60() == 0) {
        return 0;
    }
    if ((fn_803A9C74(arg0, 1) >= 2U) && (fn_803A9DF8(arg0, &lbl_8059FE60, 1, 1, 1) == 0)) {
        fn_803A9F10(arg0, 1, &sp8);
        return fn_803C1668((s8)sp8);
    }
    return fn_803C1514();
}
