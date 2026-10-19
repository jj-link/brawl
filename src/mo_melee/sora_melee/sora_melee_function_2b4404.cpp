#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_2B4404(void* ptr, int shouldDelete) {
    if (ptr && shouldDelete > 0)
        __dl__FPv(ptr);
    return ptr;
}
