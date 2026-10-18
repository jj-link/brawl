#pragma force_active on
extern "C" {
extern void fn_41_24D0(void*, short);
extern void __dl__FPv(void*);
}

extern "C" void* fn_41_2FADC(void* ptr, short flag) {
    if (ptr != 0) {
        fn_41_24D0((char*)ptr + 0x38, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
