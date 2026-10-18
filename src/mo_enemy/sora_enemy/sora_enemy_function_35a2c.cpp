#pragma force_active on
extern "C" void fn_41_359C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_35A2C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_359C0((char*)ptr + 4, (short)-1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
