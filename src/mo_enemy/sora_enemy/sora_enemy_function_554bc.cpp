#pragma force_active on
extern "C" void fn_41_556F4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_554BC(void* ptr, int deleting) {
    if (ptr != 0) {
        fn_41_556F4((char*)ptr + 8, -1);
        if ((short)deleting > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
