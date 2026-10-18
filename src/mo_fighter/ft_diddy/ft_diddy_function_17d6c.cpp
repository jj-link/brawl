#pragma force_active on
extern "C" void fn_115_17CF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_17D6C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_115_17CF4(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
