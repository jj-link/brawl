#pragma force_active on
extern "C" void* fn_41_65698(void*, short);
extern "C" void fn_41_65310(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_6537C(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_41_65698(static_cast<char*>(ptr) + 0x278, -1);
        fn_41_65310(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
