#pragma force_active on
#ifdef __cplusplus
extern "C" {
#endif
extern void __dl__FPv(void*);
#ifdef __cplusplus
}
#endif

extern "C" {
void* fn_27_3954(void* ptr, int amount) {
    if (ptr != 0 && amount > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
}
