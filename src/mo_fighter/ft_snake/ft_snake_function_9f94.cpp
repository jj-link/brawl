#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_9F94(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_64D9C(ptr, -1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
