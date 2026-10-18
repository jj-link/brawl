#pragma force_active on
extern "C" {
void fn_27_5B39C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_92_5F14(void* ptr, int count) {
    if (ptr != 0) {
        fn_27_5B39C(ptr, -1);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
