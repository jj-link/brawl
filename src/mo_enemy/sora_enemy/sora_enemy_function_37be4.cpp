#pragma force_active on
extern "C" void fn_41_37B78(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_37BE4(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_41_37B78(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
