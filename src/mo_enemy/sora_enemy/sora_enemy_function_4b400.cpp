#pragma force_active on
extern "C" void fn_41_4B7F4(void*, short);
extern "C" void fn_41_4B3A0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_4B400(void* ptr, short shouldDelete) {
    if (ptr) {
        fn_41_4B7F4(static_cast<char*>(ptr) + 0x38, -1);
        fn_41_4B3A0(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
