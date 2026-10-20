#pragma force_active on
extern "C" void* fn_27_3335CC(void*, int);
extern "C" void* fn_27_333C34(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_333560(void* ptr, int flag) {
    if (ptr) {
        fn_27_3335CC(static_cast<char*>(ptr) + 0x9C98, -1);
        fn_27_333C34(static_cast<char*>(ptr) + 4, -1);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
