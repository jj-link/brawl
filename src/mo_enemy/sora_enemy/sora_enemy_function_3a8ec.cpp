#pragma force_active on
extern "C" void fn_41_3AAC4(void*, short);
extern "C" void fn_41_3A880(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3A8EC(void* ptr, int flag) {
    if (ptr != 0) {
        fn_41_3AAC4((char*)ptr + 0x68, -1);
        fn_41_3A880((char*)ptr + 4, -1);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
