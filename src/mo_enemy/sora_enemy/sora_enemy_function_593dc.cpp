#pragma force_active on
extern "C" void fn_41_59370(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_593DC(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_59370((char*)ptr + 4, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
