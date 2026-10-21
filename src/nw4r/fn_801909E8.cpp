#pragma force_active on

extern "C" void fn_801D7718(void* a, void* b);
extern "C" void fn_801D7774(void* a, void* b);

extern "C" void fn_801909E8(void** p, int flag) {
    void* a = *p;
    void* b = *(void**)a;
    if (flag != 0) {
        fn_801D7718(a, b);
    } else {
        fn_801D7774(a, b);
    }
}
