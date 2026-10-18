#pragma force_active on
extern "C" void fn_41_51B5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_51924(void* ptr, int flag) {
    if (ptr) {
        fn_41_51B5C(static_cast<char*>(ptr) + 8, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
