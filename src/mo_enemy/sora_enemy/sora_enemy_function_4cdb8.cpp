#pragma force_active on

extern "C" void fn_41_4CEB8(void*, short);
extern "C" void fn_41_4CD4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4CDB8(void* ptr, int flag) {
    if (ptr != 0) {
        fn_41_4CEB8(static_cast<char*>(ptr) + 0x98, -1);
        fn_41_4CD4C(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
