#pragma force_active on
extern "C" float fn_27_34C964(char* base, int dummy, int idx, int j) {
    int n = *(int*)(base + 0x10);
    char* p = base + ((idx - n) << 2);
    float* arr = *(float**)(p + 0x18);
    return arr[j];
}
