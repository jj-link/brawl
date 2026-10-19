#pragma force_active on
extern "C" void* fn_123_4424(void* ptr, short count);

extern "C" void operator_delete_dummy();

extern "C" void* fn_123_12C78(void* ptr, short count) {
    if (ptr != 0) {
        fn_123_4424(ptr, 0);
        if (count > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
