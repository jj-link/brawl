#pragma force_active on
extern "C" void fn_41_3E4D4(short*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3E3E0(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_41_3E4D4(reinterpret_cast<short*>(
            static_cast<char*>(ptr) + 8), -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
