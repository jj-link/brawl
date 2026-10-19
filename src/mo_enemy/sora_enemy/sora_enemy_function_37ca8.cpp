#pragma force_active on
extern "C" void* fn_41_37C44(void* ptr, short flag);
extern "C" void* fn_41_33D4C(void* p, short n);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_37CA8(void* ptr, short val) {
    if (ptr) {
        fn_41_37C44((char*)ptr + 8, -1);
        fn_41_33D4C(ptr, 0);
        if (val > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
