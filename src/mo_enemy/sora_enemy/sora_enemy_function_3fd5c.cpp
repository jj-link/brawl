#pragma force_active on

extern "C" void fn_41_3FFA0(void*, short);
extern "C" void* fn_41_3FCFC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3FD5C(void* ptr, int shouldDelete) {
    if (ptr != 0) {
        fn_41_3FFA0(static_cast<char*>(ptr) + 0x38, -1);
        fn_41_3FCFC(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(shouldDelete) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
