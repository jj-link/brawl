#pragma force_active on
extern "C" void* fn_27_1A4D90(void* ptr, short count);

extern "C" void* fn_104_23CC0(void* ptr, short flag) {
    if (ptr != 0) {
        fn_27_1A4D90(ptr, -1);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
