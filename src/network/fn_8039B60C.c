#pragma force_active on
extern int lbl_805A1170;
extern int lbl_805A1188[2];
extern char lbl_8059FCE8[5];
extern char lbl_80491CC8[];
extern char lbl_80491CD8[];
extern void *fn_80397748(void *, unsigned char, unsigned long);
extern int fn_8039C984(int, int **);
extern char *fn_80399A58(void);
extern int fn_80397664(char *, unsigned int);
extern void fn_80397DE0(int, char *, ...);
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);

int fn_8039B60C(void) {
    char a[0x9c];
    char b[0x9c];
    int *p;
    int base;
    char *name;
    int result;

    base = lbl_805A1170 + 0x800;
    fn_80397748((void *)(lbl_805A1170 + 0x1700), 0, 0x80);
    result = fn_8039C984(0, &p);
    if (result != 0) return result;
    fn_80397748((void *)(lbl_805A1170 + 0x1780), 0, 0x80);
    result = fn_8039C984(1, &p);
    if (result != 0) return result;
    name = fn_80399A58();
    if (fn_80397664(name, 0x40) + 0xe > 0x100) {
        result = -11;
    } else {
        fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CC8);
        result = 0;
    }
    if (result != 0) return result;
    result = fn_8039832C(a, base, 2);
    if (result == 0) result = fn_80398680(a);
    if (result != 0) return result;
    name = fn_80399A58();
    if (fn_80397664(name, 0x40) + 0xe > 0x100) {
        result = -11;
    } else {
        fn_80397DE0(base, lbl_8059FCE8, name, lbl_80491CD8);
        result = 0;
    }
    if (result != 0) return result;
    result = fn_8039832C(b, base, 2);
    if (result == 0) result = fn_80398680(b);
    if (result != 0) return result;
    lbl_805A1188[0] = 0;
    lbl_805A1188[1] = 0;
    return 0;
}