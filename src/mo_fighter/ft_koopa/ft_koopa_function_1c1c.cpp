#pragma force_active on
extern "C" {
extern void fn_102_1AA4(void*, short);
extern void __dl__FPv(void*);

void* fn_102_1C1C(void* ptr, short release) {
    if (ptr != 0) {
        fn_102_1AA4(ptr, 0);
        if (release > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
