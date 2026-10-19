#pragma force_active on
extern "C" void fn_41_51B5C(void*, short);
extern "C" void fn_41_519F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_51A5C(void* ptr, int flag) {
    if (ptr) {
        fn_41_51B5C(static_cast<char*>(ptr) + 0x98, -1);
        fn_41_519F0(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
