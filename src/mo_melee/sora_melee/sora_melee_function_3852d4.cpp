#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3852D4(void* ptr, int size) {
    if (ptr && size > 0)
        __dl__FPv(ptr);
    return ptr;
}
