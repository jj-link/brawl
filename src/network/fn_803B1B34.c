#pragma force_active on
extern char lbl_8053B248[];

extern void *fn_803BE3D8(int);
extern int fn_803C0CC4(void *);
extern int fn_803B19A0(void *, int, unsigned int, void *);

int fn_803B1B34(int arg0, unsigned int arg1, void *arg2) {
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
    if (arg2 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        *(int *)(obj + 0x186c) = 10;
        return 10;
    }
    if (arg1 != 0x7f && ((arg1 & 0xffffff00) != 0 || (int)(arg1 & 0x18) == 0x18)) {
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
    r = fn_803B19A0(obj, arg0, arg1, arg2);
    if (r != 0) {
        *(int *)((char *)arg2 + 8) = 0;
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
    }
    return r;
}
