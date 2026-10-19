#pragma force_active on
extern "C" {
void fn_110_1BE0(void*, short);
void __dl__FPv(void*);

void* fn_110_1B84(void* ptr, int count) {
    if (ptr != 0) {
        fn_110_1BE0(ptr, 0);
        if ((short)count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
