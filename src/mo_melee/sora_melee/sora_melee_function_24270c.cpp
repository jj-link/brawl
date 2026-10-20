#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void fn_27_241FC4(void*, int);

extern "C" void* fn_27_24270C(void* ptr, int release) {
    if (ptr != 0) {
        fn_27_241FC4(ptr, 0);
        if (release > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
