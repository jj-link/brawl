#pragma force_active on
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void fn_41_4B6F4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B854(void* ptr, int flag) {
    if (ptr) {
        fn_41_4B7F4(static_cast<char*>(ptr) + 0x1B8, -1);
        fn_41_4B6F4(static_cast<char*>(ptr) + 4, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
