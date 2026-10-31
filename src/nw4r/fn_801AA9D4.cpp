#pragma force_active on

extern "C" {

typedef void (*FuncPtr)(void *, int, int, void *);
extern FuncPtr lbl_8040AB48[7];
extern FuncPtr lbl_8040AB64[7];
extern float lbl_805A33C8;
extern float lbl_805A33D0;

int fn_801AA9D4(void *arg0, int arg1, int arg2, unsigned int arg3) {
    unsigned int idx = (arg3 >> 1) & 7;
    if (idx == 7) {
        return 0;
    }
    if (arg1 != 0) {
        lbl_8040AB48[idx](arg0, arg2, arg2, (void *)&lbl_8040AB48);
    } else {
        lbl_8040AB64[idx](arg0, arg2, arg2, (void *)&lbl_8040AB64);
    }

    float b;
    float a;
    int ret;
    a = lbl_805A33C8;
    ret = 1;
    b = lbl_805A33D0;
    float *f = (float *)arg0;
    f[8] = a;
    f[9] = a;
    f[10] = b;
    f[11] = a;
    return ret;
}

}
