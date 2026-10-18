#pragma force_active on
extern "C" {
void fn_27_1540CC(void*, short);
void __dl__FPv(void*);

void* fn_92_6158(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_1540CC(ptr, -1);
        if ((short)flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
}
