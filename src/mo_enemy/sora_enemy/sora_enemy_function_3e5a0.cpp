#pragma force_active on
extern "C" void fn_41_3E534(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3E5A0(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_41_3E534(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
