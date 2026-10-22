#pragma force_active on
extern int fn_803A9BB4(int *p1, int p2, int p3);
extern int fn_803BC2C0(int *p1, int p2, int *p3);
extern int fn_803C291C(int a, int b);
extern char lbl_8053B248[];

int fn_803C2A2C(int arg0) {
    int sp10[4];
    int sp8;
    int r;
    r = fn_803A9BB4(sp10, arg0, 1);
    if (r == 0) {
        r = fn_803BC2C0(sp10, 0x19, &sp8);
    } else {
        *(int *)(lbl_8053B248 + 0x1C) = r;
    }
    return fn_803C291C(r, sp8);
}
