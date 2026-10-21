#pragma force_active on

extern int fn_80378084(void *, void **);

int fn_803741A4(void *arg0, void **arg1) {
    int r3 = fn_80378084(arg0, arg1);

    if (r3 != 0) {
        return r3;
    }
    *(int *)((char *)(*arg1) + 0xC) = 0;
    r3 = 0;
    *(int *)((char *)(*arg1) + 0x10) = 1;
    return r3;
}
