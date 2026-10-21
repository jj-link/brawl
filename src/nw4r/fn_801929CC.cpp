#pragma force_active on

extern "C" void fn_801D7718(void*, void*);
extern "C" void fn_801D7774(void*, void*);

extern "C" void fn_801929CC(void** a, int flag) {
    void* p = *a;
    void* q = *(void**)p;
    if (flag != 0) {
        fn_801D7718(p, q);
    } else {
        fn_801D7774(p, q);
    }
}
