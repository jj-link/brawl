#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_79_3B38(void* ptr, int flag) {
    if (ptr && flag > 0)
        __dl__FPv(ptr);
    return ptr;
}
