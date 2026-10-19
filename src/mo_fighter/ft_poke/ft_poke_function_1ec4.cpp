#pragma force_active on
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_1EC4(void* ptr, int flag) {
    if (ptr) {
        fn_27_7700(ptr, 0);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
