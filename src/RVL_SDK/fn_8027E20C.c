#pragma force_active on
extern int lbl_804E4840[];
int fn_80204E5C(void*, int);

int fn_8027E20C(int arg0, int arg1) {
    int base = fn_80204E5C(lbl_804E4840, arg0 + arg1);
    int m = arg1 - 1;
    int sum = arg1 + base;
    int aligned;
    m = ~m;
    aligned = m & sum;
    ((int*)aligned)[-1] = aligned - base;
    return aligned;
}
