#pragma force_active on
extern "C" int fn_27_32DA18(char *self, int unused, int idx, int sub) {
    int base = *(int *)(self + 0x14);
    char *q = self + ((idx - base) << 2);
    int *arr = *(int **)(q + 0x4c);
    return arr[sub];
}
