#pragma force_active on
extern "C" void fn_27_246654(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2470DC(void* ptr, int flag) {
    if (ptr != 0) {
        fn_27_246654(ptr, 0);
        if (flag > 0)
            __dl__FPv(ptr);
    }
    return ptr;
}
