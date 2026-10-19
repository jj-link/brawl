#pragma force_active on
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_27_7DE60(void* ptr, int deleteFlag) {
    if (ptr != 0 && deleteFlag > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
