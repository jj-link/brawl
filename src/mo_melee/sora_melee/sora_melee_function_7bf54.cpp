#pragma force_active on
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_7BF54(void* ptr, int deleting) {
    if (ptr != 0 && deleting > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
