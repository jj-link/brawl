#pragma force_active on
extern "C" {
void fn_112_1B64(void*, short);
void __dl__FPv(void*);

void* fn_112_1BC8(void* ptr, short flag) {
    if (ptr != 0) {
        fn_112_1B64(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
