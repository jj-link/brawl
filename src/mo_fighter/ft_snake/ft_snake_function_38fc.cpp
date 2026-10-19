#pragma force_active on
extern "C" void fn_27_64874(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_38FC(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_27_64874(ptr, 0);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
