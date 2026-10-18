#pragma force_active on
typedef short s16;

extern "C" void fn_41_5D12C(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5CEF4(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_41_5D12C(static_cast<char*>(ptr) + 8, static_cast<s16>(-1));
        if (static_cast<s16>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
