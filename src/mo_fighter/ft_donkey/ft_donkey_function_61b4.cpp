#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_61B4(void* ptr, short count) {
    if (ptr != 0) {
        fn_27_66114(ptr, -1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
