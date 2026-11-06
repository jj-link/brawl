#pragma force_active on
typedef struct Object {
    char pad[0x82c];
    int field82c;
    char pad830[8];
    int field838;
    int field83c;
} Object;
extern int lbl_805A1048;
extern void *fn_8035DFE8(int);
extern void fn_803891B8(void);
extern void fn_803893F0(void);
extern void fn_8038A2D0(void *, int, int, int, int, int, void (*)(void), void *);
extern void fn_80387D30(void *, int, int, int, void (*)(void), void *);

Object *fn_803894EC(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    Object *p;
    if (g == 0 && lbl_805A1048 != 1)
        return 0;
    p = fn_8035DFE8(0x840);
    if (p == 0)
        return 0;
    p->field838 = h;
    p->field83c = i;
    p->field82c = 0;
    fn_8038A2D0((char *)p + 0x4c, a, b, c, d, g, fn_803891B8, p);
    fn_80387D30(p, e, f, g, fn_803893F0, p);
    return p;
}