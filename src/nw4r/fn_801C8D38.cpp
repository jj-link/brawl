#pragma force_active on
extern "C" unsigned int fn_801C6BAC(void*);
extern "C" int fn_801C6BB4(void*);
extern "C" int fn_801C6BFC(void*, unsigned int, int*);
extern "C" int fn_801C6C04(void*, int*);

extern "C" int fn_801C8D38(void* unused, void* arg) {
    int a[2];
    int b[6];
    unsigned int n = fn_801C6BAC(arg);
    unsigned int size = (n * 0x60 + 3) & ~3;
    for (unsigned int i = 0; i < n; i++) {
        if (fn_801C6BFC(arg, i, a)) {
            for (int j = 0; j < a[0]; j++) {
                if (a[1])
                    size += (a[1] + 0x3f) & ~3;
            }
        }
    }
    size += (fn_801C6BB4(arg) * 8 + 7) & ~3;
    if (fn_801C6C04(arg, b)) {
        size += (b[0] * 0x44c + 3) & ~3;
        size += (b[2] * 0xb3c + 3) & ~3;
        size += (b[5] * 0x1bc + 3) & ~3;
        size += (b[1] * 0xd8 + 3) & ~3;
    }
    return size;
}