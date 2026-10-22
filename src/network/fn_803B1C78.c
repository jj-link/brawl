#pragma force_active on
extern char lbl_8053B248[];
extern int fn_803C0CC4(void *);
extern int fn_803B161C(void *);

int fn_803B1C78(void *arg0) {
    char *obj;
    int r;
    if (arg0 == 0) {
        *(int *)(lbl_8053B248 + 0x1c) = 10;
        return 10;
    }
    obj = *(char **)((char *)arg0 + 8);
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
    r = fn_803B161C(arg0);
    if (r != 0) {
        *(int *)(lbl_8053B248 + 0x1c) = r;
        *(int *)(obj + 0x186c) = r;
    }
    return r;
}
