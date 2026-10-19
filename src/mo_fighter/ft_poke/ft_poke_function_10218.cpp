#pragma force_active on
extern "C" void* fn_116_10274(void* ptr, short count);
void operator delete(void* p);

extern "C" void* fn_116_10218(void* ptr, short flags) {
    if (ptr != 0) {
        fn_116_10274(ptr, 0);
        if (flags > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
