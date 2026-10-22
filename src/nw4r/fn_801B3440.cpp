#pragma force_active on
extern "C" void* fn_80204E5C(void*, unsigned int);
extern "C" void fn_801AC13C(void*, int, int, int);
extern "C" int lbl_80466410[];

extern "C" void* fn_801B3440(void* arg0, int* arg1, int arg2) {
    void* result = 0;
    unsigned int size = (unsigned int)(arg2 * 4 + 0xEF) & 0xFFFFFFFC;

    if (arg1 != 0) {
        *arg1 = (int)size;
    }
    if (arg0 != 0) {
        result = fn_80204E5C(arg0, size);
        if (result == 0) {
            return 0;
        }
        if (result != 0) {
            fn_801AC13C(result, (int)arg0, (int)((char*)result + 0xEC), arg2);
            *(int*)result = (int)lbl_80466410;
            *(int*)((char*)result + 0xE8) = 0;
        }
    }
    return result;
}
