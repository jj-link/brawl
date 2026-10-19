#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void fn_27_D5070(void*, short);
void* fn_41_229C(void* ptr, short flag);
}

extern "C" void* fn_41_229C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_D5070(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
