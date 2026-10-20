#pragma force_active on
extern "C" float fn_27_341228(char *self, int unused, int idx, int sub) {
    int base = *(int *)(self + 0x10);
    float *row = *(float **)(self + (idx - base) * 4 + 0x18);
    return row[sub];
}
