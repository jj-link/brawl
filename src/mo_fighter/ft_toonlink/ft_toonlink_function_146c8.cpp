#pragma force_active on
extern "C" void fn_121_5F68(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_146C8(void* ptr, short count) {
    if (ptr != 0) {
        fn_121_5F68(ptr, 0);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
