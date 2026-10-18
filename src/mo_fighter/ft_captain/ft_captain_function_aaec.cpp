#pragma force_active on
extern "C" {
void fn_100_AA8C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_AAEC(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_100_AA8C(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
