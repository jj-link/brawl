#pragma force_active on
extern char lbl_8053B248[];
extern int fn_803C19B0(int);
extern void fn_803C290C(int);

void fn_803C2958(int *arg0) {
    int *p;
    int result;

    p = arg0;
    if (arg0 == 0) {
        goto fail;
    }
    result = *arg0;
    if (result != 0) {
        goto loop;
    }

fail:
    result = 10;
    *(int *)(lbl_8053B248 + 0x1C) = result;
    goto done;

loop:
    for (; *p != 0; p++) {
        result = fn_803C19B0(*p);
        if (result != 0) {
            fn_803C290C(result);
            return;
        }
    }

done:
    fn_803C290C(result);
}
