#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_61B8(void* ptr, short flag) {
    if (ptr && flag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
