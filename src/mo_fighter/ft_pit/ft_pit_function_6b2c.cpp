#pragma force_active on
extern "C" {
void fn_27_66114(void*, short);
void __dl__FPv(void*);
void* fn_112_6B2C(void* ptr, short p2) {
    if (ptr != 0) {
        fn_27_66114(ptr, -1);
        if (p2 > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
