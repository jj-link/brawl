#pragma force_active on
extern "C" void fn_41_2EE30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2EE70(void* ptr, int count) {
    if (ptr != 0) {
        fn_41_2EE30(ptr, 0);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
