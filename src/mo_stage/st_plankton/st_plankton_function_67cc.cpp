#pragma force_active on
extern "C" {
void __dl__FPv(void* ptr);
}

extern "C" void* fn_74_67CC(void* ptr, int size) {
    if (ptr != 0 && size > 0) {
        __dl__FPv(ptr);
    }
    return ptr;
}
