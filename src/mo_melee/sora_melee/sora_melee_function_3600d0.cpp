#pragma force_active on
extern "C" int fn_27_3600D0(char* p, int unused, int a, int idx) {
    int* arr;
    char* base = p + ((a - *(int*)(p + 0x14)) << 2);
    arr = *(int**)(base + 0x3c);
    return arr[idx];
}
