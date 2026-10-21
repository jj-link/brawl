#pragma force_active on

extern "C" void fn_801D7718(void*, int);
extern "C" void fn_801D7774(void*, int);

extern "C" void fn_801929FC(void** self, int flag) {
    void* p = *self;
    int v = *(int*)p;
    if (flag != 0) {
        fn_801D7718(p, v);
    } else {
        fn_801D7774(p, v);
    }
}
