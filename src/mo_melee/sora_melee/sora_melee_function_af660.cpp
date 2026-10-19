#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_AF660(void* arg0, int arg1) {
    void* result = arg0;
    if (result && arg1 > 0) {
        __dl__FPv(result);
    }
    return result;
}
