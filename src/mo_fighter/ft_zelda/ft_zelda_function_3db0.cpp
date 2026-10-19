#pragma force_active on
extern "C" void* fn_104_3E0C(void* ptr, short size);

extern "C" void* fn_104_3DB0(void* ptr, short flag) {
    if (ptr != 0) {
        fn_104_3E0C(ptr, 0);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
