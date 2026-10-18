#pragma force_active on
extern "C" void* fn_114_1511C(void* ptr, short size) {
    if (ptr != 0 && size > 0) {
        operator delete(ptr);
    }
    return ptr;
}
