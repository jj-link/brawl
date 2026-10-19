#pragma force_active on
extern "C" void fn_126_1980(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_1BB0(void* ptr, int flag) {
    if (ptr != 0) {
        fn_126_1980(ptr, 0);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
