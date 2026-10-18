#pragma force_active on
extern "C" {
void fn_27_5B39C(void*, short);
void __dl__FPv(void*);

void* fn_100_5D34(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_5B39C(ptr, -1);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
