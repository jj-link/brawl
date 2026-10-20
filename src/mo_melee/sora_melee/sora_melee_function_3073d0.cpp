#pragma force_active on
extern "C" float fn_27_3073D0(void *arg0, int arg1, int arg2, int arg3) {
    int *base = (int *)arg0;
    float **table = (float **)((char *)base + (arg2 - base[4]) * 4);
    return table[6][arg3];
}
