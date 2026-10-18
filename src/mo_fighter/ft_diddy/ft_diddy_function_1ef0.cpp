#pragma force_active on
extern "C" {
void fn_27_7700(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_115_1EF0(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_7700(ptr, 0);
        if ((short)flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
