#pragma force_active on
extern "C" void fn_41_1F850(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_1F890(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        if (ptr != 0) {
            fn_41_1F850(ptr, 0);
        }
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
