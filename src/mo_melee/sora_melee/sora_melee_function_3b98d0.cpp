#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_3B98D0(void* ptr, int release) {
    if (ptr != 0 && release > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}
