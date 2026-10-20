#pragma force_active on
extern "C" void* fn_27_D8(void*, int);

extern "C" void* fn_27_2AE0(void* ptr, int size) {
    if (ptr) {
        fn_27_D8(ptr, 0);
        if (size > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
