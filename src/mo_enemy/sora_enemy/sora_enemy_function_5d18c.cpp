#pragma force_active on
extern "C" void fn_41_5D12C(void*, short);
extern "C" void fn_41_5D02C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5D18C(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_41_5D12C(static_cast<char*>(ptr) + 0xc8, -1);
        fn_41_5D02C(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
