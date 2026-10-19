#pragma force_active on
extern "C" void* fn_121_482C(void* ptr, short count);

extern "C" void* fn_121_486C(void* ptr, short flag) {
    if (ptr != 0) {
        fn_121_482C(ptr, 0);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
