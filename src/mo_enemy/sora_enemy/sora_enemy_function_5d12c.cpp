#pragma force_active on
extern "C" void fn_41_2D244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5D12C(void* ptr, short count) {
    if (ptr != 0) {
        fn_41_2D244(static_cast<char*>(ptr) + 4, -1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
