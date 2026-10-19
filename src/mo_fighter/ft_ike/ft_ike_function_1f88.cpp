#pragma force_active on
extern "C" void fn_27_1362C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_1F88(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_1362C(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
