#pragma force_active on
extern "C" void fn_41_3FFA0(void*, short);
extern "C" void fn_41_3FDC8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3FE34(void* ptr, short count) {
    if (ptr) {
        fn_41_3FFA0(static_cast<char*>(ptr) + 0x98, -1);
        fn_41_3FDC8(static_cast<char*>(ptr) + 4, -1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
