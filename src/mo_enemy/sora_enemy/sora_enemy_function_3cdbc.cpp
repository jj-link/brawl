#pragma force_active on
extern "C" void fn_41_3CD5C(void*, short);
extern "C" void fn_41_3CC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3CDBC(void* ptr, int flag) {
    if (ptr != 0) {
        fn_41_3CD5C(static_cast<char*>(ptr) + 104, -1);
        fn_41_3CC5C(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
