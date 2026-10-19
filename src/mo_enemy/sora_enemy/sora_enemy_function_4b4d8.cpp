#pragma force_active on
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void fn_41_4B46C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B4D8(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_41_4B7F4(static_cast<char*>(ptr) + 0x98, -1);
        fn_41_4B46C(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
