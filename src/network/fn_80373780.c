#pragma force_active on
extern int fn_8035DFE8(int arg0);

int fn_80373780(int *self, int arg) {
    int r = fn_8035DFE8(arg);
    int ret;
    self[0] = r;
    if (r == 0) {
        ret = 0;
    } else {
        self[1] = arg;
        ret = 1;
    }
    return ret;
}
