#pragma force_active on
extern char lbl_8053B248[];

extern void *fn_803BE3D8(int);
extern int fn_803C0CC4(void *);
extern int fn_803AA540(void *);
extern int fn_803BB6C8(void *, int, int, int *);

int fn_803BC2C0(int arg0, int arg1, int *arg2) {
    char *obj;
    int r;

    if (arg2 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    *arg2 = 0;
    if (arg0 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    obj = fn_803BE3D8(arg0);
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    r = fn_803C0CC4(obj);
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
        return r;
    }
    if (fn_803AA540(obj) != 0 && arg1 != 2) {
        return 0xB;
    }
    r = fn_803BB6C8(obj, arg0, arg1, arg2);
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
        return r;
    }
    *(int *)(obj + 0x15e0) += 1;
    return r;
}
