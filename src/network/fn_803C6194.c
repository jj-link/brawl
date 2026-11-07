#pragma force_active on
extern int fn_803C2AB0(void);
extern int fn_803C2AF8(int, int *);

int fn_803C6194(int *arg0, int arg1) {
    int value[5];
    *arg0 = -1;
    if (arg1 != 0) {
        if (fn_803C2AF8(arg1, value) == 0) {
            *arg0 = value[0];
            return 0;
        }
        return fn_803C2AB0();
    }
    return -1;
}
