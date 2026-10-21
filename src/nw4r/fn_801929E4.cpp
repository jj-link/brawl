#pragma force_active on
extern "C" void fn_801D7718(void*, void*);
extern "C" void fn_801D7774(void*, void*);

extern "C" void fn_801929E4(void** a, int b) {
    void* c = *a;
    void* d = *(void**)c;
    if (b != 0) {
        fn_801D7718(c, d);
    } else {
        fn_801D7774(c, d);
    }
}
