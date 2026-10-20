#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void* fn_41_62438(void* ptr, short flags);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_62498(void* ptr, short flags) {
    if (ptr != 0) {
        short idx = -1;
        fn_41_62CC4(static_cast<char*>(ptr) + 0x38, idx);
        fn_41_62438(static_cast<char*>(ptr) + 4, idx);
        if (flags > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
