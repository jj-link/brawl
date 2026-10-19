#pragma force_active on
extern "C" int fn_41_15FD4(void*, int);
extern "C" float fn_41_1E6A4(int, int);
extern float lbl_41_rodata_C3C;

extern "C" float fn_41_16234(void* a, int b) {
    if (b == -1) {
        return lbl_41_rodata_C3C;
    }
    return fn_41_1E6A4(fn_41_15FD4(a, b), *(int*)((char*)a + 0x20));
}
