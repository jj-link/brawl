#pragma force_active on
extern "C" void* fn_27_64930(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2188(void* ptr, short size) {
    if (ptr != 0) {
        fn_27_64930(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
