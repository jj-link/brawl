#pragma force_active on
extern char lbl_8053B248[];
extern int lbl_8059FE30;

extern int fn_803A9DF8(int, void *, int, int, int);
extern void *fn_803BE3D8(int);
extern int fn_803C0CC4(void *);
extern int fn_803B11A4(void *, int);
extern void fn_803C13C8(void *);

int fn_803B1F80(int arg0)
{
    void *object;
    int result;

    if (arg0 == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }

    if (fn_803A9DF8(arg0, &lbl_8059FE30, 1, 0, 1) == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }

    object = fn_803BE3D8(arg0);
    if (object == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 9;
        return 9;
    }

    result = fn_803C0CC4(object);
    if (result != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = result;
        *(int *)((char *)object + 0x186C) = result;
        return result;
    }

    result = fn_803B11A4(object, arg0);
    if (result != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = result;
        *(int *)((char *)object + 0x186C) = result;
    } else {
        fn_803C13C8(object);
    }

    return result;
}
