#pragma force_active on
extern "C" void fn_95_1F80(void* ptr, short count);

extern "C" void* __dl__FPv(void* ptr);

extern "C" void* fn_95_1F24(void* ptr, short count) {
    if (ptr != 0) {
        fn_95_1F80(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
