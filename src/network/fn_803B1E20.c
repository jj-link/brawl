#pragma force_active on
extern char lbl_8053B248[];
extern int lbl_8059FE30;

extern int fn_803A9DF8(int, void *, int, int, int);
extern int fn_803B0140(void *);
extern int fn_803B0174(void *, int);
extern int fn_803B0920(void *, int, int, int);
extern void *fn_803BE3D8(int);
extern int fn_803C0E80(void);

int fn_803B1E20(int arg0)
{
    int *obj;
    int ret;
    union {
        int value;
        void *pointer;
    } mode;

    if (arg0 == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }

    if (fn_803A9DF8(arg0, &lbl_8059FE30, 1,
                   (int)(mode.pointer = 0), 1) == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 10;
        return 10;
    }

    obj = fn_803BE3D8(arg0);
    if (obj == 0) {
        *(int *)(lbl_8053B248 + 0x1C) = 9;
        return 9;
    }

    ret = fn_803C0E80();
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        obj[0x186C / 4] = ret;
        return ret;
    }

    obj[0x1608 / 4] = mode.value;
    ret = fn_803B0920(obj, arg0, 0, 0);
    if (ret != 0) {
        *(int *)(lbl_8053B248 + 0x1C) = ret;
        obj[0x186C / 4] = ret;
    } else {
        ret = fn_803B0140(obj);
        if (ret != 0) {
            *(int *)(lbl_8053B248 + 0x1C) = ret;
            obj[0x186C / 4] = ret;
        } else {
            ret = fn_803B0174(obj, 0);
            if (ret != 0) {
                *(int *)(lbl_8053B248 + 0x1C) = ret;
                obj[0x186C / 4] = ret;
            }
        }
    }

    obj[0x1608 / 4] = 0;
    return ret;
}
