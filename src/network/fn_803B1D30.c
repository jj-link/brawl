#pragma force_active on
extern char lbl_8053B248[];

extern void *fn_803BE3D8(int);
extern int fn_803C0CC4(void *);
extern int fn_803B1420(void *, int, int);

int fn_803B1D30(int arg0, int arg1) {
    char *obj;
    int r;

    if (arg0 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    obj = fn_803BE3D8(arg0);
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 9;
        return 9;
    }
    if (arg1 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(obj + 0x186c) = 10;
        return 10;
    }
    r = fn_803C0CC4(obj);
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
        return r;
    }
    r = fn_803B1420(obj, arg0, arg1);
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
    }
    return r;
}
