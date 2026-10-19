#pragma force_active on
extern "C" void* fn_107_16148(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_160EC(void* ptr, short count) {
    if (ptr != 0) {
        fn_107_16148(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
