#pragma force_active on
extern "C" void* fn_107_1F34(void* ptr, short count);

extern "C" void* fn_107_1ED8(void* ptr, short flag) {
    if (ptr != 0) {
        fn_107_1F34(ptr, 0);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
