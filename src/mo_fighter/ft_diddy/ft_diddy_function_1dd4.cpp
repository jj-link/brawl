#pragma force_active on
extern "C" void* fn_115_1E30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1DD4(void* ptr, short count) {
    if (ptr != 0) {
        fn_115_1E30(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
