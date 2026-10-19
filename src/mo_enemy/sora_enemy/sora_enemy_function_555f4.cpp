#pragma force_active on
extern "C" void fn_41_556F4(void*, short);
extern "C" void fn_41_55588(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_555F4(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_556F4((char*)ptr + 0x98, -1);
        fn_41_55588((char*)ptr + 4, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
