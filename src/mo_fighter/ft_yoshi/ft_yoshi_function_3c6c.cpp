#pragma force_active on
extern "C" void* fn_95_3CC8(void* ptr, short count);

extern "C" void* fn_95_3C6C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_95_3CC8(ptr, 0);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
