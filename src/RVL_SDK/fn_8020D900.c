#pragma force_active on
extern int fn_8020CAD4(void);
extern int fn_8020D7B0(void);
extern int fn_80214A98(int, unsigned int *, unsigned int *);
extern int fn_8020CAEC(int);
extern int fn_8020D844(unsigned int *, unsigned int *, const char *);
extern char lbl_8047C290[];

int fn_8020D900(unsigned int a, unsigned int b, unsigned int *out)
{
    unsigned int x = -1;
    unsigned int y = -1;
    unsigned int z = -1;
    unsigned int w = -1;
    unsigned int z2, w2;
    unsigned int flags;
    unsigned int y2;
    int result;

    if (!fn_8020CAD4())
        return -128;

    result = fn_80214A98(fn_8020D7B0(), &x, &y);
    if (result != 0)
        return fn_8020CAEC(result);

    result = fn_8020D844(&z, &w, lbl_8047C290);
    if (result != 0)
        return fn_8020CAEC(result);

    w2 = w;
    z2 = z;
    y2 = y;
    flags = 0;

    if (x + a > 0x400)
        flags |= 1;
    if (y2 + b > 0x21)
        flags |= 2;
    if (z2 + a > 0x4400)
        flags |= 4;
    if (w2 + b > 0xFA0)
        flags |= 8;

    *out = flags;
    return 0;
}
