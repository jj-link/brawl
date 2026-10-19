#pragma force_active on
extern "C" void fn_41_3AAC4(void*, short);
extern "C" void* fn_41_3A820(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3A880(void* ptr, short flag) {
    if (ptr != 0) {
        short s = -1;
        fn_41_3AAC4((char*)ptr + 0x38, s);
        fn_41_3A820((char*)ptr + 4, s);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
