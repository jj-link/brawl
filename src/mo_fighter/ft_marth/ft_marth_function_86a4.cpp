#pragma force_active on
extern "C" int fn_106_8698();

extern "C" int fn_106_86A4(char* base, int unused, int i, int j) {
    char* p = (base - 0x10000) + fn_106_8698() * 0x24;
    p = p + (i << 2);
    int* arr = *(int**)(p - 0x75F0);
    return arr[j];
}
