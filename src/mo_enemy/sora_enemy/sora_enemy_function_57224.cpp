#pragma force_active on
extern "C" void fn_41_571B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_57224(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_41_571B8(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
