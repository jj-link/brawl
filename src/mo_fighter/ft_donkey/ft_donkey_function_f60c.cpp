#pragma force_active on
extern "C" void* fn_92_F668(void* ptr, short size);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_F60C(void* ptr, short size) {
    if (ptr != 0) {
        fn_92_F668(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
