#pragma force_active on
extern "C" void* fn_97_1EB0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_1E54(void* ptr, short size) {
    if (ptr != 0) {
        fn_97_1EB0(ptr, 0);
        if (size > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
