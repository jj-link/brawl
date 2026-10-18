#pragma force_active on
extern "C" void* fn_115_46CC(void* ptr, short count);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_115_171AC(void* ptr, short count) {
    if (ptr != 0) {
        fn_115_46CC(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
