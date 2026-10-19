#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_CB5CC(void* ptr, signed int count) {
    if (ptr && count > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
