#pragma force_active on
extern "C" void fn_112_11D50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_11DC8(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_112_11D50(ptr, 0);
        if ((short)shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
