#pragma force_active on
extern int *fn_8035B1C4(void *, int *);

int fn_80388738(void *arg0, int arg1, int arg2) {
    int sp8;
    int *temp_r3;

    if (arg0 == 0) {
        return 0;
    }
    sp8 = arg1;
    temp_r3 = fn_8035B1C4(*(void **)((char *)arg0 + 0x18), &sp8);
    if (temp_r3 == 0) {
        return arg2;
    }
    return temp_r3[1];
}